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
 * @file    hal_lld.c
=======
 * @file    simulator/posix/hal_lld.c
>>>>>>> upstream/master
 * @brief   Posix simulator HAL subsystem low level driver code.
 *
 * @addtogroup POSIX_HAL
 * @{
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

#include "hal.h"

/*===========================================================================*/
/* Driver exported variables.                                                */
/*===========================================================================*/

/*===========================================================================*/
/* Driver local variables and types.                                         */
/*===========================================================================*/

static struct timeval nextcnt;
<<<<<<< HEAD
static struct timeval tick = {0, 1000000 / CH_CFG_ST_FREQUENCY};
=======
static struct timeval tick = {0UL, 1000000UL / OSAL_ST_FREQUENCY};
>>>>>>> upstream/master

/*===========================================================================*/
/* Driver local functions.                                                   */
/*===========================================================================*/

/*===========================================================================*/
/* Driver interrupt handlers.                                                */
/*===========================================================================*/

/*===========================================================================*/
/* Driver exported functions.                                                */
/*===========================================================================*/

/**
 * @brief Low level HAL driver initialization.
 */
void hal_lld_init(void) {
<<<<<<< HEAD
=======

>>>>>>> upstream/master
#if defined(__APPLE__)
  puts("ChibiOS/RT simulator (OS X)\n");
#else
  puts("ChibiOS/RT simulator (Linux)\n");
#endif
  gettimeofday(&nextcnt, NULL);
  timeradd(&nextcnt, &tick, &nextcnt);
}

/**
 * @brief   Interrupt simulation.
 */
void _sim_check_for_interrupts(void) {
  struct timeval tv;
<<<<<<< HEAD

#if HAL_USE_SERIAL
  if (sd_lld_interrupt_pending()) {
    _dbg_check_lock();
    if (chSchIsPreemptionRequired())
      chSchDoReschedule();
    _dbg_check_unlock();
    return;
=======
  bool int_occurred = false;

#if HAL_USE_SERIAL
  if (sd_lld_interrupt_pending()) {
    int_occurred = true;
>>>>>>> upstream/master
  }
#endif

  gettimeofday(&tv, NULL);
  if (timercmp(&tv, &nextcnt, >=)) {
<<<<<<< HEAD
    timeradd(&nextcnt, &tick, &nextcnt);
=======
    int_occurred = true;
    timeradd(&nextcnt, &tick, &nextcnt);

>>>>>>> upstream/master
    CH_IRQ_PROLOGUE();

    chSysLockFromISR();
    chSysTimerHandlerI();
    chSysUnlockFromISR();

    CH_IRQ_EPILOGUE();
<<<<<<< HEAD

=======
  }

  if (int_occurred) {
>>>>>>> upstream/master
    _dbg_check_lock();
    if (chSchIsPreemptionRequired())
      chSchDoReschedule();
    _dbg_check_unlock();
  }
}

/** @} */
