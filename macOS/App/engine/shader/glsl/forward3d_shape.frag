//-----------------------------------------------
//
//	This file is part of the Siv3D Engine.
//
//	Copyright (c) 2008-2021 Ryo Suzuki
//	Copyright (c) 2016-2021 OpenSiv3D Project
//
//	Licensed under the MIT License.
//
//-----------------------------------------------

# version 410

//
//	PSInput
//
layout(location = 0) in vec3 WorldPosition;
layout(location = 1) in vec2 UV;
layout(location = 2) in vec3 Normal;

//
//	PSOutput
//
layout(location = 0) out vec4 FragColor;

//
//	Constant Buffer
//
layout(std140) uniform PSPerView
{
	vec3 g_eyePosition;
};

layout(std140) uniform PSPerMaterial
{
	vec4 g_diffuseColor;
};

//
//	Functions
//
void main()
{
	FragColor = g_diffuseColor;
}
