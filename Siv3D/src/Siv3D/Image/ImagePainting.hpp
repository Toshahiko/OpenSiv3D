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

# pragma once
# include <Siv3D/Image.hpp>

namespace s3d
{
	namespace ImagePainting
	{
		void Paint(const Color* pSrc, Color* pDst,
			int32 width, int32 height, int32 srcWidth, int32 dstWidth, Color color);

		void Stamp(const Color* pSrc, Color* pDst,
			int32 width, int32 height, int32 srcWidth, int32 dstWidth, Color color);

		void Overwrite(const Color* pSrc, Color* pDst,
			int32 width, int32 height, int32 srcWidth, int32 dstWidth);
	}
}
