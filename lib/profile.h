/*
 * profile.h - defines Profile struct
 *
 * Copyright (C) 2014-2016 Symeon Huang <hzwhuang@gmail.com>
 *
 * This file is part of the libQtShadowsocks.
 *
 * libQtShadowsocks is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published
 * by the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * libQtShadowsocks is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with libQtShadowsocks; see the file LICENSE. If not, see
 * <http://www.gnu.org/licenses/>.
 */

#ifndef PROFILE_H
#define PROFILE_H

#include <string>
#include <cstdint>

namespace QSS {

struct ProfilePrivate;

class Profile {
public:
    Profile();

    ~Profile();

    const std::string& name() const;
    const std::string& method() const;
    const std::string& password() const;
    const std::string& serverAddress() const;
    const std::string& localAddress() const;
    uint16_t serverPort() const;
    uint16_t localPort() const;
    int timeout() const;
    bool httpProxy() const;
    bool debug() const;
    bool otaEnabled() const;

    std::string toUri() const;
    std::string toUriSip002() const;

    void setName(const std::string& name);
    void setMethod(const std::string& method);
    void setPassword(const std::string& password);
    void setServerAddress(const std::string& server);
    void setLocalAddress(const std::string& local);
    void setServerPort(uint16_t);
    void setLocalPort(uint16_t);
    void setTimeout(int);
    void setHttpProxy(bool);
    void enableDebug();
    void disableDebug();
    void enableOta();
    void disableOta();

    // Both the original schema and the SIP002 are supported by this function
    static Profile fromUri(const std::string&);

private:
    ProfilePrivate *const d_private; // For future extension (to keep ABI compatible)

    /**
     * Essential data are stored directly as members in this class
     * Don't remove or change any these members, which would break ABI compatiblity
     */
    std::string d_name;
    std::string d_method;
    std::string d_password;
    std::string d_serverAddress;
    std::string d_localAddress;
    uint16_t d_serverPort;
    uint16_t d_localPort;
    int d_timeout;
    bool d_debug;
};

}
#endif // PROFILE_H
