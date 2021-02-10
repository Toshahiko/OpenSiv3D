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

# include "GlyphCacheCommon.hpp"

namespace s3d
{
	bool ProcessControlCharacter(const char32 ch, Vec2& penPos, int32& line, const Vec2& basePos, const double scale, const FontData& font)
	{
		if (not IsControl(ch))
		{
			return false;
		}

		switch (ch)
		{
		case U'\t':
			penPos.x += (font.getProperty().spaceWidth * scale * 4);
			break;
		case U'\n':
			penPos.x = basePos.x;
			penPos.y += (font.getProperty().height() * scale);
			++line;
			break;
		default:
			break;
		}

		return true;
	}

	bool CacheGlyph(const FontData& font, const Image& image, const GlyphInfo& glyphInfo,
		BufferImage& buffer, HashTable<GlyphIndex, GlyphCache>& glyphTable)
	{
		if (not buffer.image)
		{
			const int32 fontSize = font.getProperty().fontPixelSize;
			const int32 baseWidth =
				fontSize <= 16 ? 512 :
				fontSize <= 32 ? 768 :
				fontSize <= 48 ? 1024 :
				fontSize <= 64 ? 1536 :
				fontSize <= 256 ? 2048 : 4096;
			const int32 baseHeight = (fontSize <= 256 ? 256 : 512);
			buffer.image.resize(baseWidth, baseHeight, buffer.backgroundColor);
		}

		buffer.penPos.x += buffer.padding;

		const int32 bitmapWidth		= image.width();
		const int32 bitmapHeight	= image.height();

		if (buffer.image.width() < (buffer.penPos.x + (bitmapWidth + buffer.padding)))
		{
			buffer.penPos.x = buffer.padding;
			buffer.penPos.y += (buffer.currentMaxHeight + (buffer.padding * 2));
			buffer.currentMaxHeight = 0;
		}

		if (buffer.image.height() < (buffer.penPos.y + (bitmapHeight + buffer.padding)))
		{
			const int32 newHeight = ((buffer.penPos.y + (bitmapHeight + buffer.padding)) + 255) / 256 * 256;

			if (BufferImage::MaxImageHeight < newHeight)
			{
				return false;
			}

			buffer.image.resizeRows(newHeight, buffer.backgroundColor);
		}

		image.overwrite(buffer.image, buffer.penPos);

		GlyphCache cache;
		cache.info					= glyphInfo;
		cache.textureRegionLeft		= static_cast<int16>(buffer.penPos.x);
		cache.textureRegionTop		= static_cast<int16>(buffer.penPos.y);
		cache.textureRegionWidth	= static_cast<int16>(bitmapWidth);
		cache.textureRegionHeight	= static_cast<int16>(bitmapHeight);
		glyphTable.emplace(glyphInfo.glyphIndex, cache);

		buffer.currentMaxHeight = Max(buffer.currentMaxHeight, bitmapHeight);
		buffer.penPos.x += (bitmapWidth + buffer.padding);

		return true;
	}
}
