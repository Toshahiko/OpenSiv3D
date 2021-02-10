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

# pragma once
# include <Siv3D/Font.hpp>
# include <Siv3D/HashTable.hpp>
# include "IGlyphCache.hpp"
# include "GlyphCacheCommon.hpp"

namespace s3d
{
	class MSDFGlyphCache : public IGlyphCache
	{
	public:

		MSDFGlyphCache() = default;

		RectF draw(const FontData& font, StringView s, const Vec2& pos, double size, const ColorF& color) override;

		RectF drawBase(const FontData& font, StringView s, const Vec2& pos, double size, const ColorF& color) override;

		[[nodiscard]]
		RectF region(const FontData& font, StringView s, const Vec2& pos, double size) override;

		[[nodiscard]]
		RectF regionBase(const FontData& font, StringView s, const Vec2& pos, double size) override;

		void setBufferWidth(int32 width) override;

		[[nodiscard]]
		int32 getBufferWidth() const noexcept override;

		bool preload(const FontData& font, const StringView s) override;

		[[nodiscard]]
		const Texture& getTexture() const noexcept override;

	private:

		static constexpr int32 DefaultBuffer = 2;

		[[nodiscard]]
		bool prerender(const FontData& font, StringView s, const Array<GlyphCluster>& clusters);

		[[nodiscard]]
		RectF draw(const FontData& font, StringView s, const Vec2& pos, double size, const ColorF& color, bool usebasePos);

		[[nodiscard]]
		RectF region(const FontData& font, StringView s, const Vec2& pos, double size, bool usebasePos);

		HashTable<GlyphIndex, GlyphCache> m_glyphTable;

		Texture m_texture;

		BufferImage m_buffer = { .backgroundColor = Color{ 0, 0 } };
	};
}
