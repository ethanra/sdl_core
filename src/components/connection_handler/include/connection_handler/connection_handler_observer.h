/**
 * \file connection_handlerObserver.hpp
 * \brief connection_handlerObserver class.
 *
 * Copyright (c) 2013, Ford Motor Company
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * Redistributions of source code must retain the above copyright notice, this
 * list of conditions and the following disclaimer.
 *
 * Redistributions in binary form must reproduce the above copyright notice,
 * this list of conditions and the following
 * disclaimer in the documentation and/or other materials provided with the
 * distribution.
 *
 * Neither the name of the Ford Motor Company nor the names of its contributors
 * may be used to endorse or promote products derived from this software
 * without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef SRC_COMPONENTS_CONNECTIONHANDLER_INCLUDE_CONNECTIONHANDLER_CONNECTION_HANDLER_OBSERVER_H_
#define SRC_COMPONENTS_CONNECTIONHANDLER_INCLUDE_CONNECTIONHANDLER_CONNECTION_HANDLER_OBSERVER_H_

#include "connection_handler/device.h"
#include "connection_handler/connection.h"

/**
 * \namespace connection_handler
 * \brief SmartDeviceLink connection_handler namespace.
 */
namespace connection_handler {

/**
  * \brief Enum describing possible types of sessions: RPC for API messages,
  Navi for video streaming.
  */
enum ServiceType {
  kUnknownSession = -1,
  kRPCSession = 0x07,
  kNaviSession = 0x0B,
  kBulkSession = 0x0F
};

/**
 * \class ConnectionHandlerObserver
 * \brief ConnectionHandlerObserver class
 */
class ConnectionHandlerObserver {
  public:
    /**
     * \brief Available devices list updated.
     *
     * Called when device scanning initiated with scanForNewDevices
     * is completed.
     *
     * \param DeviceList New list of available devices.
     **/
    virtual void OnDeviceListUpdated(
      const connection_handler::DeviceList& device_list) = 0;

    /**
     * \brief Removes device.
     *
     * Called when device has been removed from a list.
     *
     * \param DeviceHandle Handle of removed device.
     **/
    virtual void RemoveDevice(
      const connection_handler::DeviceHandle device_handle) = 0;

    /**
     * \brief Callback function used by connection_handler
     * when Mobile Application initiates start of new session.
     * \param deviceHandle Device identifier within which session has to be started.
     * \param sessionKey Key of started session.
     * \param firstSessionKey Session key of first session in this connection.
     */
    virtual bool OnSessionStartedCallback(
      connection_handler::DeviceHandle device_handle, int session_key,
      int first_session_key, ServiceType type = ServiceType::kRPCSession) = 0;

    /**
     * \brief Callback function used by connection_handler
     * when Mobile Application initiates session ending.
     * \param sessionKey Key of session which should be ended
     * \param firstSessionKey Session key of first session in this connection
     */
    virtual void OnSessionEndedCallback(int session_key,
                                        int first_session_key) = 0;

  protected:
    /**
     * \brief Destructor
     */
    virtual ~ConnectionHandlerObserver() {
    }
};
}/* namespace connection_handler */

#endif  // SRC_COMPONENTS_CONNECTIONHANDLER_INCLUDE_CONNECTIONHANDLER_CONNECTION_HANDLER_OBSERVER_H_
