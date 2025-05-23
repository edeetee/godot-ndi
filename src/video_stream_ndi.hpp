/*
https://github.com/unvermuthet/godot-ndi
		(C) 2025 Henry Muth - unvermuthet

This Source Code Form is subject to the terms of the Mozilla Public
License, v. 2.0. If a copy of the MPL was not distributed with this
file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */

#pragma once

#include "ndi.hpp"
#include "ndi_finder.hpp"
#include "video_stream_playback_ndi.hpp"

#include <godot_cpp/classes/video_stream.hpp>

using namespace godot;

class NDIFinder;
class VideoStreamPlaybackNDI;

class VideoStreamNDI : public VideoStream {
	GDCLASS(VideoStreamNDI, VideoStream)

public:
	VideoStreamNDI();
	VideoStreamNDI(const NDIlib_source_t p_source);
	~VideoStreamNDI();

	static bool equal(VideoStreamNDI *a, VideoStreamNDI *b);

	void set_name(const String p_name);
	String get_name() const;

	void set_bandwidth(const NDIlib_recv_bandwidth_e p_bandwidth);
	NDIlib_recv_bandwidth_e get_bandwidth() const;

	Ref<VideoStreamPlayback> _instantiate_playback() override;

protected:
	static void _bind_methods();
	void _validate_property(PropertyInfo &p_property);

private:
	CharString name = nullptr;
	CharString url = nullptr;
	NDIlib_recv_bandwidth_e bandwidth = NDIlib_recv_bandwidth_highest;

	void _set_url(const String p_url);
	String _get_url() const;

	NDIFinder *finder = nullptr;
	void sources_changed();
};

VARIANT_ENUM_CAST(NDIlib_recv_bandwidth_e);
