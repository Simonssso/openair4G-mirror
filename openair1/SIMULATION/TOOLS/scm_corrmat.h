/*******************************************************************************
    OpenAirInterface 
    Copyright(c) 1999 - 2014 Eurecom

    OpenAirInterface is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.


    OpenAirInterface is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with OpenAirInterface.The full GNU General Public License is 
   included in this distribution in the file called "COPYING". If not, 
   see <http://www.gnu.org/licenses/>.

  Contact Information
  OpenAirInterface Admin: openair_admin@eurecom.fr
  OpenAirInterface Tech : openair_tech@eurecom.fr
  OpenAirInterface Dev  : openair4g-devel@eurecom.fr
  
  Address      : Eurecom, Campus SophiaTech, 450 Route des Chappes, CS 50193 - 06904 Biot Sophia Antipolis cedex, FRANCE

 *******************************************************************************/
double R22_sqrt[6][32] = {
{0.921700, -0.000000, 0.010380, -0.027448, -0.250153, 0.294754, 0.005961, 0.010769, 0.010380, 0.027448, 0.921700, 0.000000, -0.011595, -0.004130, -0.250153, 0.294754, -0.250153, -0.294754, -0.011595, 0.004130, 0.921700, 0.000000, 0.010380, -0.027448, 0.005961, -0.010769, -0.250153, -0.294754, 0.010380, 0.027448, 0.921700, 0.000000},
{0.923810, 0.000000, 0.004069, 0.027832, 0.151730, 0.350180, -0.009882, 0.006114, 0.004069, -0.027832, 0.923810, 0.000000, 0.011218, -0.003029, 0.151730, 0.350180, 0.151730, -0.350180, 0.011218, 0.003029, 0.923810, -0.000000, 0.004069, 0.027832, -0.009882, -0.006114, 0.151730, -0.350180, 0.004069, -0.027832, 0.923810, 0.000000},
{0.927613, 0.000000, 0.014253, 0.025767, -0.061171, -0.367133, 0.009258, -0.007340, 0.014253, -0.025767, 0.927613, -0.000000, -0.011138, -0.003942, -0.061171, -0.367133, -0.061171, 0.367133, -0.011138, 0.003942, 0.927613, 0.000000, 0.014253, 0.025767, 0.009258, 0.007340, -0.061171, 0.367133, 0.014253, -0.025767, 0.927613, 0.000000},
{0.869794, -0.000000, -0.010613, -0.001218, 0.399115, 0.289852, -0.004464, -0.004096, -0.010613, 0.001218, 0.869794, -0.000000, -0.005276, -0.002978, 0.399115, 0.289852, 0.399115, -0.289852, -0.005276, 0.002978, 0.869794, -0.000000, -0.010613, -0.001218, -0.004464, 0.004096, 0.399115, -0.289852, -0.010613, 0.001218, 0.869794, 0.000000},
{0.919726, -0.000000, 0.038700, -0.111146, 0.217804, 0.300925, 0.045531, -0.013659, 0.038700, 0.111146, 0.919726, 0.000000, -0.027201, 0.038983, 0.217804, 0.300925, 0.217804, -0.300925, -0.027201, -0.038983, 0.919726, 0.000000, 0.038700, -0.111146, 0.045531, 0.013659, 0.217804, -0.300925, 0.038700, 0.111146, 0.919726, 0.000000},
{0.867608, -0.000000, 0.194097, -0.112414, -0.418811, 0.095938, -0.081264, 0.075727, 0.194097, 0.112414, 0.867608, -0.000000, -0.106125, -0.032801, -0.418811, 0.095938, -0.418811, -0.095938, -0.106125, 0.032801, 0.867608, 0.000000, 0.194097, -0.112414, -0.081264, -0.075727, -0.418811, -0.095938, 0.194097, 0.112414, 0.867608, 0.000000},
};
double R21_sqrt[6][8] = {
{0.922167, 0.000000,-0.250280, 0.294903,-0.250280, -0.294903,0.922167, 0.000000},
{0.924238, 0.000000,0.151801, 0.350342,0.151801, -0.350342,0.924238, 0.000000},
{0.928080, 0.000000,-0.061202, -0.367318,-0.061202, 0.367318,0.928080, 0.000000},
{0.869860, 0.000000,0.399145, 0.289874,0.399145, -0.289874,0.869860, 0.000000},
{0.927225, 0.000000,0.219580, 0.303378,0.219580, -0.303378,0.927225, 0.000000},
{0.896133, 0.000000,-0.432581, 0.099092,-0.432581, -0.099092,0.896133, 0.000000},
};
double R12_sqrt[6][8] = {
{0.999494, 0.000000,0.011256, -0.029765,0.011256, 0.029765,0.999494, 0.000000},
{0.999537, 0.000000,0.004402, 0.030114,0.004402, -0.030114,0.999537, 0.000000},
{0.999497, 0.000000,0.015358, 0.027764,0.015358, -0.027764,0.999497, 0.000000},
{0.999925, -0.000000,-0.012201, -0.001400,-0.012201, 0.001400,0.999925, 0.000000},
{0.991912, 0.000000,0.041738, -0.119870,0.041738, 0.119870,0.991912, 0.000000},
{0.968169, 0.000000,0.216594, -0.125443,0.216594, 0.125443,0.968169, 0.000000},
};
