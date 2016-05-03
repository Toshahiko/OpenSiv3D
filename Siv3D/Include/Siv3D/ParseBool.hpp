﻿//-----------------------------------------------
//
//	This file is part of the Siv3D Engine.
//
//	Copyright (C) 2008-2016 Ryo Suzuki
//	Copyright (C) 2016 OpenSiv3D Project
//
//	Licensed under the MIT License.
//
//-----------------------------------------------

# pragma once
# include "Fwd.hpp"
# include "String.hpp"
# include "Optional.hpp"

namespace s3d
{
	inline bool ParseBool(const String& str)
	{
		return str.trimmed().lowercase().compare(L"true") == 0;
	}

	inline Optional<bool> ParseBoolOpt(const String& str)
	{
		const String t = str.trimmed().lowercase();

		if (t.compare(L"true") == 0)
		{
			return true;
		}
		else if (t.compare(L"false") == 0)
		{
			return false;
		}
		else
		{
			return none;
		}
	}
}
