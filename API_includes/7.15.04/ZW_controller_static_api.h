/* © 2018 Silicon Laboratories Inc.
 */
/***************************  ZW_CONTROLLER_STATIC_API.H  *******************
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
 * Description: Z-Wave Static Controller node application interface
 *
 * Author:   Johann Sigfredsson
 *
 * Last Changed By:  $Author: sse $
 * Revision:         $Revision: 28973 $
 * Last Changed:     $Date: 2014-06-03 15:14:50 +0200 (Tue, 03 Jun 2014) $
 *
 ****************************************************************************/
#ifndef _ZW_CONTROLLER_STATIC_API_H_
#define _ZW_CONTROLLER_STATIC_API_H_

#ifndef ZW_CONTROLLER_STATIC
#define ZW_CONTROLLER_STATIC
#endif

/****************************************************************************/
/*                              INCLUDE FILES                               */
/****************************************************************************/
/*These are a part of the standard static controller API*/
#include <ZW_controller_api.h>
/****************************************************************************/
/*                     EXPORTED TYPES and DEFINITIONS                       */
/****************************************************************************/
/****************************************************************************
* Functionality specific for the Static Controller API.
****************************************************************************/

/*========================   ZW_CreateNewPrimaryCtrl   ======================
**
**    Create a new primary controller
**
**    The modes are:
**
**    CREATE_PRIMARY_START          Start the creation of a new primary
**    CREATE_PRIMARY_STOP           Stop the creation of a new primary
**    CREATE_PRIMARY_STOP_FAILED    Report that the replication failed
**
**    ADD_NODE_OPTION_NORMAL_POWER    Set this flag in bMode for High Power inclusion.
**
**    Side effects:
**
**--------------------------------------------------------------------------*/
#define ZW_CREATE_NEW_PRIMARY_CTRL(MODE, FUNC) ZW_CreateNewPrimaryCtrl(MODE, FUNC)


/****************************************************************************/
/*                              EXPORTED DATA                               */
/****************************************************************************/


/****************************************************************************/
/*                           EXPORTED FUNCTIONS                             */
/*                 Implemented within the application moduls                */
/****************************************************************************/

/****************************************************************************/
/*                           EXPORTED FUNCTIONS                             */
/*                 Implemented within the Z-Wave controller modules         */
/****************************************************************************/

/*========================   ZW_CreateNewPrimaryCtrl   ======================
**
**    Create a new primary controller
**
**    The modes are:
**
**    CREATE_PRIMARY_START          Start the creation of a new primary
**    CREATE_PRIMARY_STOP           Stop the creation of a new primary
**    CREATE_PRIMARY_STOP_FAILED    Report that the replication failed
**
**    ADD_NODE_OPTION_NORMAL_POWER    Set this flag in bMode for High Power inclusion.
**
**    Side effects:
**
**--------------------------------------------------------------------------*/
void
ZW_CreateNewPrimaryCtrl(BYTE bMode,
                        VOID_CALLBACKFUNC(completedFunc)(LEARN_INFO*));



#endif /* _ZW_CONTROLLER_STATIC_API_H_ */

