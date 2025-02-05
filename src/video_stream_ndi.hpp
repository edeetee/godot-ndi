/*
https://github.com/unvermuthet/godot-ndi
		(C) 2025 Henry Muth - unvermuthet

This Source Code Form is subject to the terms of the Mozilla Public
License, v. 2.0. If a copy of the MPL was not distributed with this
file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */

#pragma once

#include "includes.hpp"

using namespace godot;

class VideoStreamNDI : public VideoStream {
	GDCLASS(VideoStreamNDI, VideoStream)

	public:
		VideoStreamNDI();
		VideoStreamNDI(const NDIlib_source_t p_source);
		~VideoStreamNDI();

		void set_name(const String p_name);
		String get_name() const;

		void set_url(const String p_url);
		String get_url() const;

		void set_bandwidth(const NDIlib_recv_bandwidth_e p_bandwidth);
		NDIlib_recv_bandwidth_e get_bandwidth() const;
		
		Ref<VideoStreamPlayback> _instantiate_playback() override;

	protected:
		static void _bind_methods();
		void _validate_property(PropertyInfo & p_property);

	private:
		CharString name;
		CharString url;
		NDIlib_recv_bandwidth_e bandwidth;

		NDIFinder* finder;
		String available_sources_hint;
		void update_available_sources_hint();

};

VARIANT_ENUM_CAST(NDIlib_recv_bandwidth_e);
