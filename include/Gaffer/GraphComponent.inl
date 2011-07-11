//////////////////////////////////////////////////////////////////////////
//  
//  Copyright (c) 2011, John Haddon. All rights reserved.
//  Copyright (c) 2011, Image Engine Design Inc. All rights reserved.
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

#ifndef GAFFER_GRAPHCOMPONENT_INL
#define GAFFER_GRAPHCOMPONENT_INL

#include "boost/tokenizer.hpp"

namespace Gaffer
{

template<typename T>
typename T::Ptr GraphComponent::getChild( const std::string &name )
{
	// preferring the nasty casts over mainaining two nearly identical implementations for getChild.
	return IECore::constPointerCast<T>( const_cast<const GraphComponent *>( this )->getChild<T>( name ) );
}

template<typename T>
typename T::ConstPtr GraphComponent::getChild( const std::string &name ) const
{
	if( !name.size() )
	{
		return 0;
	}
	
	typedef boost::tokenizer<boost::char_separator<char> > Tokenizer;

	Tokenizer t( name, boost::char_separator<char>( "." ) );
	const GraphComponent *result = this;
	for( Tokenizer::iterator tIt=t.begin(); tIt!=t.end(); tIt++ )
	{
		const GraphComponent *child = 0;
		IECore::InternedString internedName( *tIt );
		for( ChildContainer::const_iterator it=result->m_children.begin(); it!=result->m_children.end(); it++ )
		{
			if( (*it)->m_name==internedName )
			{
				child = it->get();
				break;
			}
		}
		if( !child )
		{
			return 0;
		}
		result = child;
	}
	
	return IECore::runTimeCast<const T>( result );
}

template<typename T>
FilteredChildIterator<TypePredicate<T> > GraphComponent::childrenBegin() const
{
	return FilteredChildIterator<TypePredicate<T> >( m_children.begin(), m_children.end() );
}
		
template<typename T>
FilteredChildIterator<TypePredicate<T> > GraphComponent::childrenEnd() const
{
	return FilteredChildIterator<TypePredicate<T> >( m_children.end(), m_children.end() );
}
		
template<typename T>
T *GraphComponent::parent()
{
	return IECore::runTimeCast<T>( m_parent );
}

template<typename T>
const T *GraphComponent::parent() const
{
	return IECore::runTimeCast<const T>( m_parent );
}

template<typename T>
T *GraphComponent::ancestor()
{
	return static_cast<T *>( ancestor( T::staticTypeId() ) );
}

template<typename T>
const T *GraphComponent::ancestor() const
{
	return static_cast<const T *>( ancestor( T::staticTypeId() ) );
}

template<typename T>
typename T::Ptr GraphComponent::commonAncestor( ConstGraphComponentPtr other )
{
	return IECore::staticPointerCast<T>( commonAncestor( other, T::staticTypeId() ) );
}

template<typename T>
typename T::ConstPtr GraphComponent::commonAncestor( ConstGraphComponentPtr other ) const
{
	return IECore::staticPointerCast<const T>( commonAncestor( other, T::staticTypeId() ) );
}
		
} // namespace Gaffer

#endif // GAFFER_GRAPHCOMPONENT_INL
