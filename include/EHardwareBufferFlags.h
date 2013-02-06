// Copyright (C) 2002-2012 Nikolaus Gebhardt
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in irrlicht.h

#ifndef __E_HARDWARE_BUFFER_FLAGS_INCLUDED__
#define __E_HARDWARE_BUFFER_FLAGS_INCLUDED__

namespace irr
{
namespace scene
{
//���ݶ�д��Ƶ�ʣ�����GPU�ϴ洢��������
	enum E_HARDWARE_MAPPING
	{
		//! Don't store on the hardware
		EHM_NEVER=0,

		//! Rarely changed, usually stored completely on the hardware
		EHM_STATIC,

		//! Sometimes changed, driver optimized placement
		EHM_DYNAMIC,

		//! Always changed, cache optimizing on the GPU
		EHM_STREAM
	};
//�洢buffer�����ݣ�����buffer
	enum E_BUFFER_TYPE
	{
		//! Does not change anything
		EBT_NONE=0,
		//! Change the vertex mapping��vertex buffer
		EBT_VERTEX,
		//! Change the index mapping��index buffer
		EBT_INDEX,
		//! Change both vertex and index mapping to the same value
		EBT_VERTEX_AND_INDEX
	};

} // end namespace scene
} // end namespace irr

#endif

