/*
 * Copyright 2011 Gabriel Mendonça
 *
 * This file is part of BIVoD.
 * BIVoD is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * BIVoD is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with BIVoD.  If not, see <http://www.gnu.org/licenses/>.
 *
 *
 * VideoPeerPlugin.h
 *
 *  Created on: 06/09/2011
 *      Author: gabriel
 */

#ifndef VIDEOPEERPLUGIN_H_
#define VIDEOPEERPLUGIN_H_

#include <libtorrent/extensions.hpp>

using namespace libtorrent;

namespace bivod {

class VideoPeerPlugin: public peer_plugin {
public:
	VideoPeerPlugin(peer_connection* pc);

	/**
	 * Requests a new piece from peer.
	 * Called when peer sends an unchoke message.
	 */
	virtual bool on_unchoke();

private:
	peer_connection* m_peer_connection;
};

} /* namespace bivod */

#endif /* VIDEOPEERPLUGIN_H_ */