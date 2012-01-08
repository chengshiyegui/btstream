/*
 * Copyright 2011 Gabriel Mendonça
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
 * VideoTorrentManager.h
 *
 *  Created on: 06/09/2011
 *      Author: gabriel
 */

#ifndef VIDEOTORRENTMANAGER_H_
#define VIDEOTORRENTMANAGER_H_

#include <libtorrent/session.hpp>
#include <boost/shared_ptr.hpp>

#include "VideoBuffer.h"
#include "Exception.h"

using namespace libtorrent;

namespace btstream {

struct Status {
	int download_rate;
	int upload_rate;
	float progress;
};

/**
 * Manages video torrents through libtorrent.
 * Sends downloaded pieces to a VideoBuffer in order to be played.
 */
class VideoTorrentManager {
public:

	/**
	 * Default constructor.
	 */
	VideoTorrentManager();

	/**
	 * Destructor.
	 */
	~VideoTorrentManager();

	/**
	 * Initializes session for specified torrent download and returns the
	 * number of pieces.
	 */
	int add_torrent(std::string file_name, std::string save_path = ".")
			throw (Exception);

	/**
	 * Starts download of the video file.
	 * The downloaded pieces will be added to the given VideoBuffer.
	 * A feeding thread will be started.
	 */
	void start_download(boost::shared_ptr<VideoBuffer> video_buffer) throw (Exception);

	/**
	 * Adds downloaded pieces to VideoBuffer.
	 * Pieces will be get through a libtorrent alert.
	 */
	void feed_video_buffer();

	/**
	 * Returns a Status object with statistics like download rate,
	 * upload rate, progress and current class.
	 */
	Status get_status();

private:
	session m_session;
	torrent_handle m_torrent_handle;
	boost::shared_ptr<VideoBuffer> m_video_buffer;
	int m_pieces_to_play;

	boost::shared_ptr<boost::thread> m_feeding_thread;
};

} /* namespace btstream */

#endif /* VIDEOTORRENTMANAGER_H_ */
