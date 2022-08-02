﻿//-----------------------------------------------
//
//	This file is part of the Siv3D Engine.
//
//	Copyright (c) 2008-2022 Ryo Suzuki
//	Copyright (c) 2016-2022 OpenSiv3D Project
//
//	Licensed under the MIT License.
//
//-----------------------------------------------

# include <Siv3D/AudioCodec/CAudioCodec.hpp>

namespace s3d
{
	ISiv3DAudioCodec* ISiv3DAudioCodec::Create()
	{
		return new CAudioCodec;
	}
}
