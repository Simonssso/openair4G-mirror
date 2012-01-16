/*******************************************************************************

  Eurecom OpenAirInterface
  Copyright(c) 1999 - 2011 Eurecom

  This program is free software; you can redistribute it and/or modify it
  under the terms and conditions of the GNU General Public License,
  version 2, as published by the Free Software Foundation.

  This program is distributed in the hope it will be useful, but WITHOUT
  ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
  FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
  more details.

  You should have received a copy of the GNU General Public License along with
  this program; if not, write to the Free Software Foundation, Inc.,
  51 Franklin St - Fifth Floor, Boston, MA 02110-1301 USA.

  The full GNU General Public License is included in this distribution in
  the file called "COPYING".

  Contact Information
  Openair Admin: openair_admin@eurecom.fr
  Openair Tech : openair_tech@eurecom.fr
  Forums       : http://forums.eurecom.fsr/openairinterface
  Address      : Eurecom, 2229, route des crêtes, 06560 Valbonne Sophia Antipolis, France

*******************************************************************************/

/*! \file otg_tx_socket.c
* \brief function containing the OTG TX traffic generation functions with sockets
* \author A. Hafsaoui
* \date 2011
* \version 0.1
* \company Eurecom
* \email: openair_tech@eurecom.fr
* \note
* \warning
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#include "otg_tx.h"
#include "otg_tx_socket.h"
#include "otg_vars.h"
#include "../MATH/oml.h"
#include "../../../openair1/PHY/CODING/defs.h"
#include "../MATH/oml.h"
#include "net_data.h"
#include "otg_config.h"




void socket_packet_send(int src, int dst, int state){


	if (g_otg->ip_v[src]==0) { 
		if (g_otg->trans_proto[src]==0)
			client_socket_tcp_ip4(src, dst, state);
		else
			client_socket_tcp_ip6(src, dst, state);

	}
	else {	
		if (g_otg->trans_proto[src]==0)
			client_socket_udp_ip4(src, dst, state);
		else
			client_socket_udp_ip6(src, dst, state);
	}

}



void client_socket_tcp_ip4(int src, int dst, int state)
{

#if defined (WIN32)
    #include <winsock2.h>
    typedef int socklen_t;
#elif defined (linux)
    #include <sys/types.h>
    #include <sys/socket.h>
    #include <netinet/in.h>
    #include <arpa/inet.h>
    #include <unistd.h>
    #define INVALID_SOCKET -1
    #define SOCKET_ERROR -1
    #define closesocket(s) close(s)
    typedef int SOCKET;
    typedef struct sockaddr_in SOCKADDR_IN;
    typedef struct sockaddr SOCKADDR;
#endif
 
#include <stdio.h>
#include <stdlib.h>
#define PORT 7777


printf("client TCP IPv4\n");

	#if defined (WIN32)
        WSADATA WSAData;
        int erreur = WSAStartup(MAKEWORD(2,2), &WSAData);
	#else
        int erreur = 0;
	#endif
 
	SOCKET sock;
	SOCKADDR_IN sin;
	char buffer[32] = "aymen";
	int sock_err;
	double idt;
	int size;
	char *payload;
 
    /* Si les sockets Windows fonctionnent */
    if(!erreur)
    {
        /* Création de la socket */
        sock = socket(AF_INET, SOCK_STREAM, 0);
 
        /* Configuration de la connexion */
        sin.sin_addr.s_addr = inet_addr("127.0.0.1");
        sin.sin_family = AF_INET;
        sin.sin_port = htons(PORT);
 
        /* Si l'on a réussi à se connecter */
        if(connect(sock, (SOCKADDR*)&sin, sizeof(sin)) != SOCKET_ERROR)
        {
            printf("Create socket %s with dst port %d\n", inet_ntoa(sin.sin_addr), htons(sin.sin_port));
            
	//	int i;
	//	for(i=0;i<=2;i++){ 

	//idt=time_dist(src, dst, state);					
	size=size_dist(src, dst, state);
	printf("packet size= %d \n", size);
	payload=payload_pkts(size);

                   
			sock_err = send(sock, payload, strlen(payload), 0);
 
                    if(sock_err != SOCKET_ERROR)
                        printf("Transmitted payload : %s\n", payload);
                    else
                        printf("Transmission Error\n");
		}

	//}
        /* sinon, on affiche "Impossible de se connecter" */
        else
        {
            printf("Connection is not possible\n");
        }
 
	
        /* On ferme la socket */
        closesocket(sock);
 
        #if defined (WIN32)
            WSACleanup();
        #endif
    }
}






void client_socket_tcp_ip6(int src, int dst, int state)
{

printf("client TCP IPv6\n");

}

void client_socket_udp_ip4(int src, int dst, int state)
{

printf("client UDP IPv4\n");

}

void client_socket_udp_ip6(int src, int dst, int state)
{

printf("client UDP IPv6\n");

}





