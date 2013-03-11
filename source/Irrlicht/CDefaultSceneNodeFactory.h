// Copyright (C) 2002-2012 Nikolaus Gebhardt
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in irrlicht.h

#ifndef __C_DEFAULT_SCENE_NODE_FACTORY_H_INCLUDED__
#define __C_DEFAULT_SCENE_NODE_FACTORY_H_INCLUDED__

#include "ISceneNodeFactory.h"
#include "irrArray.h"
#include "irrString.h"

namespace irr
{
namespace scene
{
	class ISceneNode;
	class ISceneManager;
	/*一个典型的Abstract Factory模式
	  将创建不同种类的node的方法抽象到CDefaultSceneNodeFactory中
      通过addSceneNode()方法的参数来判断创建何种类型的node,针对所有node的基类ISceneNode编程
	  充分体现了“programming to interface”
	 
	  而ISceneNodeFactory提供了抽象的工厂类的接口，只要派生这个接口，就能实现用户自定义的node。
	
	 addSceneNode是通过代理Manager指针，调用各个创建node的方法。这也说明所有的创建node的方法，例如addMeshSceneNode（）
	 都要在CSceneManager中实现，从增加了CSceneManager的内聚。可以考虑在CDefaultSceneNodeFactory::addSceneNode（）中直接new
	 出各种类型的node。从而彻底的杜绝scene::ISceneNode * node = smgr->addSphereSceneNode();这样不优雅的方式
	*/

	//!	Interface making it possible to dynamicly create scene nodes and animators
	class CDefaultSceneNodeFactory : public ISceneNodeFactory
	{
	public:

		CDefaultSceneNodeFactory(ISceneManager* mgr);

		//! adds a scene node to the scene graph based on its type id
		/** \param type: Type of the scene node to add.
		\param parent: Parent scene node of the new node, can be null to add the scene node to the root.
		\return Returns pointer to the new scene node or null if not successful. */
		virtual ISceneNode* addSceneNode(ESCENE_NODE_TYPE type, ISceneNode* parent=0);

		//! adds a scene node to the scene graph based on its type name
		/** \param typeName: Type name of the scene node to add.
		\param parent: Parent scene node of the new node, can be null to add the scene node to the root.
		\return Returns pointer to the new scene node or null if not successful. */
		virtual ISceneNode* addSceneNode(const c8* typeName, ISceneNode* parent=0);

		//! returns amount of scene node types this factory is able to create
		virtual u32 getCreatableSceneNodeTypeCount() const;

		//! returns type name of a createable scene node type by index
		/** \param idx: Index of scene node type in this factory. Must be a value between 0 and
		uetCreatableSceneNodeTypeCount() */
		virtual const c8* getCreateableSceneNodeTypeName(u32 idx) const;

		//! returns type of a createable scene node type
		/** \param idx: Index of scene node type in this factory. Must be a value between 0 and
		getCreatableSceneNodeTypeCount() */
		virtual ESCENE_NODE_TYPE getCreateableSceneNodeType(u32 idx) const;

		//! returns type name of a createable scene node type 
		/** \param idx: Type of scene node. 
		\return: Returns name of scene node type if this factory can create the type, otherwise 0. */
		virtual const c8* getCreateableSceneNodeTypeName(ESCENE_NODE_TYPE type) const;

	private:

		ESCENE_NODE_TYPE getTypeFromName(const c8* name) const;

		struct SSceneNodeTypePair
		{
			SSceneNodeTypePair(ESCENE_NODE_TYPE type, const c8* name)
				: Type(type), TypeName(name)
			{}

			ESCENE_NODE_TYPE Type;
			core::stringc TypeName;
		};

		core::array<SSceneNodeTypePair> SupportedSceneNodeTypes;

		ISceneManager* Manager;
	};


} // end namespace scene
} // end namespace irr

#endif

