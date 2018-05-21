/*
<<<<<<< HEAD
    ChibiOS - Copyright (C) 2006..2015 Giovanni Di Sirio
=======
    ChibiOS - Copyright (C) 2006..2018 Giovanni Di Sirio
>>>>>>> upstream/master

    Licensed under the Apache License, Version 2.0 (the "License");
    you may not use this file except in compliance with the License.
    You may obtain a copy of the License at

        http://www.apache.org/licenses/LICENSE-2.0

    Unless required by applicable law or agreed to in writing, software
    distributed under the License is distributed on an "AS IS" BASIS,
    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
    See the License for the specific language governing permissions and
    limitations under the License.
*/

/**
<<<<<<< HEAD
 * @file    hal_lld.h
=======
 * @file    simulator/posix/hal_lld.h
>>>>>>> upstream/master
 * @brief   Posix simulator HAL subsystem low level driver header.
 *
 * @addtogroup POSIX_HAL
 * @{
 */

<<<<<<< HEAD
#ifndef _HAL_LLD_H_
#define _HAL_LLD_H_

=======
#ifndef HAL_LLD_H
#define HAL_LLD_H

#if defined(WIN32)
#include <windows.h>
#else
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>
#include <fcntl.h>
#endif
>>>>>>> upstream/master
#include <stdio.h>

/*===========================================================================*/
/* Driver constants.                                                         */
/*===========================================================================*/

/**
 * @brief   Platform name.
 */
<<<<<<< HEAD
#define PLATFORM_NAME   "Posix Simulator"
=======
#if defined(WIN32)
#define PLATFORM_NAME   "Win32 Simulator"
#else
#define PLATFORM_NAME   "Posix Simulator"
#endif
>>>>>>> upstream/master

/*===========================================================================*/
/* Driver pre-compile time settings.                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Derived constants and error checks.                                       */
/*===========================================================================*/

/*===========================================================================*/
/* Driver data structures and types.                                         */
/*===========================================================================*/

/*===========================================================================*/
/* External declarations.                                                    */
/*===========================================================================*/

#ifdef __cplusplus
extern "C" {
#endif
  void hal_lld_init(void);
  void _sim_check_for_interrupts(void);
#ifdef __cplusplus
}
#endif

<<<<<<< HEAD
#endif /* _HAL_LLD_H_ */
=======
#endif /* HAL_LLD_H */
>>>>>>> upstream/master

/** @} */
