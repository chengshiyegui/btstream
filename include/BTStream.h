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
 * BTStream.h
 *
 *  Created on: 04/12/2011
 *      Author: gabriel
 */

#ifndef BTSTREAM_H_
#define BTSTREAM_H_

#include <string>

namespace btstream {

class BTStream {
public:
	BTStream(std::string& torrent_path);
};

} /* namespace btstream */
#endif /* BTSTREAM_H_ */
