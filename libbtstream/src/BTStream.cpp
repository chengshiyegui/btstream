/*
 * Copyright (C) 2011-2012 Gabriel Mendonça
 *
 * This file is part of BTStream.
 * BTStream is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * BTStream is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with BTStream.  If not, see <http://www.gnu.org/licenses/>.
 *
 *
 * BTStream.cpp
 *
 *  Created on: 04/12/2011
 *      Author: gabriel
 */

#include "BTStream.h"

namespace btstream {

BTStream::BTStream(const std::string& torrent_path, Algorithm algorithm,
		int stream_length, const std::string seed_ip,
		const std::string save_path, unsigned short seed_port) :
		m_video_torrent_manager(new VideoTorrentManager) {

	int num_pieces;
	num_pieces = m_video_torrent_manager->add_torrent(torrent_path, algorithm,
			stream_length, save_path, seed_ip, seed_port);

	m_video_buffer = boost::shared_ptr<VideoBuffer>(
			new VideoBuffer(num_pieces));

	m_video_torrent_manager->start_download(m_video_buffer);
}

boost::shared_ptr<Piece> BTStream::get_next_piece() {
	return m_video_buffer->get_next_piece();
}

Status BTStream::get_status() {
	return m_video_torrent_manager->get_status();
}

void BTStream::unlock() {
	m_video_buffer->unlock();
}

bool BTStream::unlocked() {
	return m_video_buffer->unlocked();
}

} /* namespace btstream */
