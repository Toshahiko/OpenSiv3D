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

# include <Siv3D/GamepadInfo.hpp>
# include <Siv3D/Gamepad/IGamepad.hpp>
# include <Siv3D/Common/Siv3DEngine.hpp>

namespace s3d
{
	namespace System
	{
		Array<GamepadInfo> EnumerateGamepads()
		{
			return SIV3D_ENGINE(Gamepad)->enumerate();
		}
	}
}
