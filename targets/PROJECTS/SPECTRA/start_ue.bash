#!/bin/bash




###########################################################
THIS_SCRIPT_PATH=$(dirname $(readlink -f $0))
source $THIS_SCRIPT_PATH/env_802dot21.bash
###########################################################

###########################################################
IPTABLES=/sbin/iptables
THIS_SCRIPT_PATH=$(dirname $(readlink -f $0))
declare -x OPENAIR_DIR=""
declare -x OPENAIR1_DIR=""
declare -x OPENAIR2_DIR=""
declare -x OPENAIR3_DIR=""
declare -x OPENAIR_TARGETS=""
###########################################################

set_openair
cecho "OPENAIR_DIR     = $OPENAIR_DIR" $green
cecho "OPENAIR1_DIR    = $OPENAIR1_DIR" $green
cecho "OPENAIR2_DIR    = $OPENAIR2_DIR" $green
cecho "OPENAIR3_DIR    = $OPENAIR3_DIR" $green
cecho "OPENAIR_TARGETS = $OPENAIR_TARGETS" $green


##################################################
# LAUNCH UE  executable
##################################################
declare MAKE_IP_DRIVER_TARGET="oai_nw_drv.ko"
declare MAKE_LTE_ACCESS_STRATUM_TARGET="oaisim USE_MME=R10"
declare IP_DRIVER_NAME="oai_nw_drv"
declare LTEIF="oai0"
UE_IPv4="10.0.0.8"
UE_IPv6="2001:1::8"
UE_IPv6_CIDR=$UE_IPv6"/64"
UE_IPv4_CIDR=$UE_IPv4"/24"
#------------------------------------------------
declare -a NAS_IMEI=( 3 9 1 8 3 6 7 3 0 2 0 0 0 0 )



echo "Bringup UE interface"
rmmod -f $IP_DRIVER_NAME > /dev/null 2>&1
cecho "make $MAKE_IP_DRIVER_TARGET $MAKE_LTE_ACCESS_STRATUM_TARGET ....." $green
# bash_exec "make --directory=$OPENAIR_TARGETS/SIMU/EXAMPLES/VIRT_EMUL_1eNB $MAKE_LTE_ACCESS_STRATUM_TARGET "
bash_exec "make --directory=$OPENAIR2_DIR $MAKE_IP_DRIVER_TARGET "
#bash_exec "make --directory=$OPENAIR2_DIR/NAS/DRIVER/LITE/RB_TOOL "

bash_exec "insmod  $OPENAIR2_DIR/NAS/DRIVER/LITE/$IP_DRIVER_NAME.ko oai_nw_drv_IMEI=${NAS_IMEI[0]},${NAS_IMEI[1]},${NAS_IMEI[2]},${NAS_IMEI[3]},${NAS_IMEI[4]},${NAS_IMEI[5]},${NAS_IMEI[6]},${NAS_IMEI[7]},${NAS_IMEI[8]},${NAS_IMEI[9]},${NAS_IMEI[10]},${NAS_IMEI[11]},${NAS_IMEI[12]},${NAS_IMEI[13]}"
#bash_exec "insmod  $OPENAIR2_DIR/NAS/DRIVER/UE_LTE/$IP_DRIVER_NAME.ko"

bash_exec "ip route flush cache"

#bash_exec "ip link set $LTEIF broadcast ff:ff:ff:ff:ff:ff"
bash_exec "ip link set $LTEIF up"
sleep 1
bash_exec "ip addr add dev $LTEIF $UE_IPv4_CIDR"
bash_exec "ip addr add dev $LTEIF $UE_IPv6_CIDR"


sleep 1

bash_exec "sysctl -w net.ipv4.conf.all.log_martians=1"
assert "  `sysctl -n net.ipv4.conf.all.log_martians` -eq 1" $LINENO

echo "   Disabling reverse path filtering"
bash_exec "sysctl -w net.ipv4.conf.all.rp_filter=0"
assert "  `sysctl -n net.ipv4.conf.all.rp_filter` -eq 0" $LINENO


bash_exec "ip route flush cache"

# please add table 200 lte in file /etc/iproute2/rt_tables
ip rule add fwmark 5  table lte
ip -4 route add default dev $LTEIF table lte
ip -6 route add default dev $LTEIF table lte

# start MIH-F
xterm -hold -e $ODTONE_ROOT/dist/odtone-mihf --log 4 --conf.file $ODTONE_ROOT/dist/odtone.conf &

wait_process_started odtone-mihf

gdb --args $OPENAIR_TARGETS/SIMU/USER/oaisim -a  -l7 -u1 -b0 -M1 -p2 -g1 -D eth2  \
             --ue-ral-listening-port   1234\
             --ue-ral-link-id          ue_lte_link\
             --ue-ral-ip-address       127.0.0.1\
             --ue-mihf-remote-port     1025\
             --ue-mihf-ip-address      127.0.0.1\
             --ue-mihf-id              mihf2_ue



