// Copyright (C) 2002-2012 Nikolaus Gebhardt
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in irrlicht.h

#ifndef __E_CULLING_TYPES_H_INCLUDED__
#define __E_CULLING_TYPES_H_INCLUDED__

#include "irrTypes.h"

namespace irr
{
namespace scene
{

	//! An enumeration for all types of automatic culling for built-in scene nodes
	//视景体裁剪
	enum E_CULLING_TYPE
	{
		EAC_OFF = 0,
		EAC_BOX = 1,                                //立方体裁剪
		EAC_FRUSTUM_BOX = 2,               //视锥体裁剪
		EAC_FRUSTUM_SPHERE = 4,          //距离裁剪
		EAC_OCC_QUERY = 8
	};

	//! Names for culling type
	const c8* const AutomaticCullingNames[] =
	{
		"false",
		"box",			// camera box against node box
		"frustum_box",		// camera frustum against node box
		"frustum_sphere",	// camera frustum against node sphere
		"occ_query",	// occlusion query
		0
	};

} // end namespace scene
} // end namespace irr


#endif // __E_CULLING_TYPES_H_INCLUDED__

