#ifndef _COMPONENT_CONTEXT_H_
#define _COMPONENT_CONTEXT_H_

#include <vector>

#include "Util.h"
#include "Collider.h"
#include "SystemComponent.h"

#include "InputComponent.h"
#include "MovableComponent.h"
#include "PanelComponent.h"

#include "Blast.h"
#include "Bomb.h"
#include "Bomberman.h"
#include "Bonus.h"
#include "Floor.h"
#include "Wall.h"

class ComponentContext{

	public:
		Collider collider;

		SystemComponent<EntityComponent> components;	
		SystemComponent<InputComponent> input_components;
		SystemComponent<RenderComponent> render_components;

		SystemComponent<RenderComponent> collisionables;
		SystemComponent<MovableComponent> movables;

		SystemComponent<Blast> blasts;
		SystemComponent<Bomberman> bombermans;
		SystemComponent<Bomb> bombs;
		SystemComponent<Bonus> bonuses;
		SystemComponent<Floor> floors;
		SystemComponent<Wall> walls;

		SystemComponent<PanelComponent> panels;

		ComponentContext();
		~ComponentContext();

		float getSpeed() const;
		void setSpeed(const float &);

		void removeComponent(const EntityComponent::EntityId &);
		bool componentExist(const EntityComponent::EntityId &);
	
		void updatePanel(const EntityComponent::EntityId &);
	
		std::vector<EntityComponent::EntityId> createBlast(const Position &, const EntityComponent::EntityId &, unsigned int);
		void createWall(const Position &, bool);
		EntityComponent::EntityId createBomb(const Position &, const EntityComponent::EntityId &);
		void createBomberman(const Position &, InputComponent::KeyboardConfig &);
		void createBonus(const Position &, Bonus::BonusType = Bonus::RANDOM);
		void createFloor(const Position &);

	private:
		DISALLOW_COPY_AND_ASSIGN(ComponentContext)

		float speed;
		EntityComponent::EntityId last_id;

		struct deleteObject;

		template<class SystemComponent>
		void deleteSystem(SystemComponent &);

		template<class SystemComponent>
		void deleteComponent(SystemComponent &, const EntityComponent::EntityId &);
};

#endif
