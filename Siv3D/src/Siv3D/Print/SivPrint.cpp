﻿//-----------------------------------------------
//
//	This file is part of the Siv3D Engine.
//
//	Copyright (c) 2008-2021 Ryo Suzuki
//	Copyright (c) 2016-2021 OpenSiv3D Project
//
//	Licensed under the MIT License.
//
//-----------------------------------------------

# include <Siv3D/Print.hpp>
# include <Siv3D/Print/IPrint.hpp>
# include <Siv3D/Common/Siv3DEngine.hpp>

namespace s3d
{
	namespace detail
	{
		PrintBuffer::PrintBuffer()
			: formatData{ std::make_unique<FormatData>() } {}

		PrintBuffer::PrintBuffer(PrintBuffer&& other) noexcept
			: formatData{ std::move(other.formatData) } {}

		PrintBuffer::~PrintBuffer()
		{
			if (formatData)
			{
				Print.writeln(formatData->string);
			}
		}


		void Print_impl::write(const char32_t* s) const
		{
			SIV3D_ENGINE(Print)->write(s);
		}

		void Print_impl::write(const StringView s) const
		{
			SIV3D_ENGINE(Print)->write(s);
		}

		void Print_impl::write(const String& s) const
		{
			SIV3D_ENGINE(Print)->write(s);
		}

		void Print_impl::writeln(const char32_t* s) const
		{
			SIV3D_ENGINE(Print)->writeln(s);
		}

		void Print_impl::writeln(const StringView s) const
		{
			SIV3D_ENGINE(Print)->writeln(s);
		}

		void Print_impl::writeln(const String& s) const
		{
			SIV3D_ENGINE(Print)->writeln(s);
		}

		void Print_impl::operator()(const char32_t* s) const
		{
			writeln(s);
		}

		void Print_impl::operator()(const StringView s) const
		{
			writeln(s);
		}

		void Print_impl::operator()(const String& s) const
		{
			writeln(s);
		}
	}

	void ClearPrint()
	{
		SIV3D_ENGINE(Print)->clear();
	}
}
