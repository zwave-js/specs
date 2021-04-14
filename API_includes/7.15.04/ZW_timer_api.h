/* © 2018 Silicon Laboratories Inc.
 */
/*******************************  ZW_TIMER_API.H  ***************************
 *           #######
 *           ##  ##
 *           #  ##    ####   #####    #####  ##  ##   #####
 *             ##    ##  ##  ##  ##  ##      ##  ##  ##
 *            ##  #  ######  ##  ##   ####   ##  ##   ####
 *           ##  ##  ##      ##  ##      ##   #####      ##
 *          #######   ####   ##  ##  #####       ##  #####
 *                                           #####
 *          Z-Wave, the wireless lauguage.
 *
 *              Copyright (c) 2001
 *              Zensys A/S
 *              Denmark
 *
 *              All Rights Reserved
 *
 *    This source file is subject to the terms and conditions of the
 *    Zensys Software License Agreement which restricts the manner
 *    in which it may be used.
 *
 *---------------------------------------------------------------------------
 *
 * Description: Timer service functions that handle delayed functions calls.
 *              The time base is around 10 msec.
 *
 * Author:   Ivar Jeppesen
 *
 * Last Changed By:  $Author: jsi $
 * Revision:         $Revision: 29378 $
 * Last Changed:     $Date: 2014-07-18 16:41:06 +0200 (Fri, 18 Jul 2014) $
 *
 ****************************************************************************/
#ifndef _ZW_TIMER_API_H_
#define _ZW_TIMER_API_H_

/****************************************************************************/
/*                              INCLUDE FILES                               */
/****************************************************************************/


/****************************************************************************/
/*                     EXPORTED TYPES and DEFINITIONS                       */
/****************************************************************************/
/* One second timeout */
#define TIMER_ONE_SECOND   100

/* One time timer */
#define TIMER_ONE_TIME     0
#define TIMER_FOREVER      (BYTE)-1

/******************************  Timer **************************************
** Timer service functions that handle delayed functions calls.
** The time base is around 10 msec.
**/

/*================================   TimerStart   ============================
**    Register a function that is called when the specified time has elapsed.
**    The function is called "repeats" times before the timer is stopped.
**
** BYTE              RET Timer handle ( 1 to XX if success, 0xFF if failed)
** TimerStart(
** VOID_CALLBACKFUNC(func)(),   IN  Timeout function adddress
** BYTE timerTicks,  IN  Timeout value (value * 10 msec.)
** BYTE repeats);    IN  Number of function calls (-1: forever)
**--------------------------------------------------------------------------*/
#define ZW_TIMER_START(func,ticks,repeats) TimerStart(func,ticks,repeats)

/*================================   TimerRestart  ===========================
**    Set the specified timer back to the initial value.
**
** BYTE               RET TRUE if timer restarted
** TimerRestart(
** BYTE timerHandle); IN  Timer number to restart
**--------------------------------------------------------------------------*/
#define ZW_TIMER_RESTART(handle) TimerRestart(handle)

/*================================   TimerCancel   ===========================
**    Stop the specified timer.
**      0 and 0xFF indicates no timer running.. This is acceptable
** BYTE               RET TRUE if timer cancelled
** TimerCancel(
** BYTE timerHandle); IN  Timer number to stop
**--------------------------------------------------------------------------*/
#define ZW_TIMER_CANCEL(handle) TimerCancel(handle)


/****************************************************************************/
/*                              EXPORTED DATA                               */
/****************************************************************************/

/****************************************************************************/
/*                           EXPORTED FUNCTIONS                             */
/****************************************************************************/

/*================================   TimerStart   ============================
**    Register a function that is called when the specified time has elapsed.
**    The function is called "repeats" times before the timer is stopped.
**
**--------------------------------------------------------------------------*/
extern  BYTE              /*RET Timer handle                     */
TimerStart(
VOID_CALLBACKFUNC(func)(),      /*IN  Timeout function address          */
BYTE timerTicks,          /*IN  Timeout value (value * 10 msec.)  */
BYTE repeats);            /*IN  Number of function calls (-1: forever)  */

/*================================   TimerRestart  ===========================
**    Set the specified timer back to the initial value.
**
**--------------------------------------------------------------------------*/
extern  BYTE              /*RET TRUE if timer restarted   */
TimerRestart(
BYTE timerHandle);        /*IN  Timer number to restart   */

/*================================   TimerCancel   ===========================
**    Stop the specified timer.
**
**--------------------------------------------------------------------------*/
extern  BYTE              /*RET TRUE if timer cancelled   */
TimerCancel(
BYTE timerHandle);        /*IN  Timer number to stop      */

/*================================   getTickTime   ===========================
**    Get the value of freerunning WORD tickTime 10ms ticks in a safe way.
**--------------------------------------------------------------------------*/
extern WORD
getTickTime();

/*===========================   getTickTimePassed   ==========================
**    Get passed tickTime ticks since wStartTickTime.
**
** Only usefull if passed tickTime ticks never exceeds 0xFFFF (65535) as
** passed tickTime ticks are calculated using a WORD sized free running
** 10ms tick counter.
** - Max passed tickTime ticks = 65535 * 10ms = 655.35s = 10m 55.35s
**
**--------------------------------------------------------------------------*/
extern WORD
getTickTimePassed(
  WORD wStartTickTime);

#endif /* _ZW_TIMER_API_H_ */
