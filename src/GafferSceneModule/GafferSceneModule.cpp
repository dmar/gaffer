//////////////////////////////////////////////////////////////////////////
//
//  Copyright (c) 2012-2014, Image Engine Design Inc. All rights reserved.
//  Copyright (c) 2013, John Haddon. All rights reserved.
//
//  Redistribution and use in source and binary forms, with or without
//  modification, are permitted provided that the following conditions are
//  met:
//
//      * Redistributions of source code must retain the above
//        copyright notice, this list of conditions and the following
//        disclaimer.
//
//      * Redistributions in binary form must reproduce the above
//        copyright notice, this list of conditions and the following
//        disclaimer in the documentation and/or other materials provided with
//        the distribution.
//
//      * Neither the name of John Haddon nor the names of
//        any other contributors to this software may be used to endorse or
//        promote products derived from this software without specific prior
//        written permission.
//
//  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS
//  IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
//  THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
//  PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
//  CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
//  EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
//  PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
//  PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
//  LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
//  NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
//  SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
//////////////////////////////////////////////////////////////////////////

#include "boost/python.hpp"

#include "CoreBinding.h"
#include "FilterBinding.h"
#include "HierarchyBinding.h"
#include "TransformBinding.h"
#include "GlobalsBinding.h"
#include "OptionsBinding.h"
#include "AttributesBinding.h"
#include "SceneAlgoBinding.h"
#include "RendererAlgoBinding.h"
#include "SetAlgoBinding.h"
#include "PrimitivesBinding.h"
#include "PathMatcherBinding.h"
#include "ScenePathBinding.h"
#include "ShaderBinding.h"
#include "RenderBinding.h"
#include "ObjectProcessorBinding.h"
#include "PrimitiveVariablesBinding.h"
#include "LightTweaksBinding.h"
#include "IOBinding.h"
#include "MixinBinding.h"

using namespace boost::python;
using namespace GafferSceneModule;

BOOST_PYTHON_MODULE( _GafferScene )
{

	bindCore();
	bindFilter();
	bindTransform();
	bindGlobals();
	bindOptions();
	bindAttributes();
	bindSceneAlgo();
	bindRendererAlgo();
	bindSetAlgo();
	bindPrimitives();
	bindPathMatcher();
	bindScenePath();
	bindShader();
	bindRender();
	bindHierarchy();
	bindObjectProcessor();
	bindPrimitiveVariables();
	bindLightTweaks();
	bindIO();
	bindMixin();

}
