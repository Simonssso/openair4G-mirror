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
  
  Address      : Eurecom, Compus SophiaTech 450, route des chappes, 06451 Biot, France.

 *******************************************************************************/

/*
 * logs.h
 *
 *  Created on: Nov 22, 2013
 *      Author: Laurent Winckel
 */

#ifndef LOGS_H_
#define LOGS_H_

/* Added definition of the g_info log function to complete the set of log functions from "gmessages.h" */

#include <glib/gmessages.h>

#ifdef G_HAVE_ISO_VARARGS

#define g_info(...)     g_log (G_LOG_DOMAIN,        \
                               G_LOG_LEVEL_INFO,    \
                               __VA_ARGS__)

#else

static void
g_info (const gchar *format,
        ...)
{
  va_list args;
  va_start (args, format);
  g_logv (G_LOG_DOMAIN, G_LOG_LEVEL_INFO, format, args);
  va_end (args);
}

#endif

#endif /* LOGS_H_ */
