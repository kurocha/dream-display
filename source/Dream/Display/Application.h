//
//  Display/Application.h
//  This file is part of the "Dream" project, and is released under the MIT license.
//
//  Created by Samuel Williams on 14/09/11.
//  Copyright (c) 2011 Samuel Williams. All rights reserved.
//

#ifndef _DREAM_DISPLAY_APPLICATION_H
#define _DREAM_DISPLAY_APPLICATION_H

#include "Context.h"
#include "Scene.h"

namespace Dream
{
	namespace Display
	{
		using namespace Dream::Display;
		
		/// An abstract interface to platform specific application implementation.
		// This part of the framework is optional.
		/// You can also depend on IContext directly and embed the rendering
		/// process directly into a host-specific application for enhanced
		/// functionality.
		class IApplication;

		class IApplicationDelegate : implements IObject {
		public:
			virtual ~IApplicationDelegate ();

			virtual void application_did_finish_launching (IApplication * application);
			virtual void application_will_terminate (IApplication * application);

			virtual void application_will_enter_background (IApplication * application);
			virtual void application_did_enter_foreground (IApplication * application);
		};

		class IApplication : implements IObject {
		public:
			IApplication();
			virtual ~IApplication ();

			/// Create a display context for rendering.
			virtual Ref<IContext> create_context (Ref<Dictionary> config) abstract;

			virtual IApplicationDelegate * delegate () const abstract;
		};
	}
}

#endif
