
#include <UnitTest/UnitTest.h>

#include <Dream/Display/Scene.h>
#include <Dream/Events/Loop.h>
#include <Dream/Resources/Loader.h>

namespace Dream
{
	namespace Display
	{
		class DummyContext : public Context
		{
		public:
			void start () {}
			void stop () {}
			Vec2u size () { return {0, 0}; }
		};
		
		UnitTest::Suite SceneTestSuite {
			"Dream::Display::Scene",

			{"SceneManager",
				[](UnitTest::Examiner & examiner) {
					Ref<IContext> context = new DummyContext;
					Ref<Loop> loop = new Events::Loop;
					Ref<Resources::Loader> loader = new Resources::Loader;
					
					Ref<SceneManager> scene_manager = new SceneManager(context, loop, loader);
					
					Ref<Scene> first_scene = new Scene;
					scene_manager->push_scene(first_scene);
					
					// We need to update the scene manager:
					scene_manager->render_frame_for_time(context, 0.0);
					
					examiner << "Scene manager has correct current scene" << std::endl;
					examiner.check_equal(scene_manager->current_scene(), first_scene);
				}
			},
		};
	}
}
