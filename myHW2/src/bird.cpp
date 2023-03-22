#include "bird.h"

bird::bird(vector<bird>* const _pSelfGroup, const int _id, const ofColor _ourColor, vector<bird>* const _pEnemyGroup, vector<bird>* const _pFriendGroup, vector<bird>* const _pFriendGroup2) {
	pSelfGroup = _pSelfGroup;
	pEnemyGroup = _pEnemyGroup;
	pFriendGroup = _pFriendGroup;
	pFriendGroup2 = _pFriendGroup2;
	id = _id;
	ourColor = _ourColor;
	pos.set(ofRandom(0, ofGetWidth()), ofRandom(0, ofGetHeight()));
	vel.set(ofRandom(-2, 2), ofRandom(-2, 2));
	Size = 20;
    head = 5;

}

bird::~bird() {

}

void bird::update() {
	int separationCount = 0;
	int alignmentCount = 0;
	int cohesionCount = 0;
	separationVel.set(0, 0);
	alignmentVel.set(0, 0);
	cohesionVel.set(0, 0);
	groupCenterPos.set(0, 0);

	for (int i = 0; i < pSelfGroup->size(); i++) {
		bird& rAnother = pSelfGroup->at(i);
		if (rAnother.id != id) {
            float dist = pos.distance(rAnother.pos);
			if (dist < 15) {
				separationVel += pos - rAnother.pos;
				separationCount++;
			}
			else if (dist < 20) {
				alignmentVel += rAnother.vel.getNormalized();
				alignmentCount++;
			}
			else if (dist < 50) {
				groupCenterPos += rAnother.pos;
				cohesionCount++;
			}
		}
	}

	for (int i = 0; i < pFriendGroup->size(); i++) {
		bird& rAnother = pFriendGroup->at(i);
		float dist = pos.distance(rAnother.pos);
		if (dist < 15) {
			separationVel += pos - rAnother.pos;
			separationCount++;
		}
		else if (dist < 20) {
			alignmentVel += rAnother.vel.getNormalized();
			alignmentCount++;
		}
		else if (dist < 50) {
			groupCenterPos += rAnother.pos;
			cohesionCount++;
		}
	}

	for (int i = 0; i < pFriendGroup2->size(); i++) {
		bird& rAnother = pFriendGroup2->at(i);
		float dist = pos.distance(rAnother.pos);
		if (dist < 15) {
			separationVel += pos - rAnother.pos;
			separationCount++;
		}
		else if (dist < 20) {
			alignmentVel += rAnother.vel.getNormalized();
			alignmentCount++;
		}
		else if (dist < 50) {
			groupCenterPos += rAnother.pos;
			cohesionCount++;
		}
	}

	for (int i = 0; i < pEnemyGroup->size(); i++) {
		bird& rAnother = pEnemyGroup->at(i);
		float dist = pos.distance(rAnother.pos);
		if (dist < 50) {
			separationVel += pos - rAnother.pos;
			separationCount++;
		}
	}

	
	separationVel /= separationCount;
	separationVel.getNormalized();
	alignmentVel /= alignmentCount;
	alignmentVel.getNormalized();

	groupCenterPos /= cohesionCount;
	cohesionVel = groupCenterPos - pos;
	cohesionVel.normalize();

	vel += (separationVel*0.05) + (alignmentVel*0.001) + (cohesionVel*0.02);
	vel.scale(3);
	pos += vel;

	if (pos.x < 0) {
		vel.x *= -1;
	}
	else if (pos.x >= ofGetWidth()) {
		vel.x *= -1;
	}
	else if (pos.y < 0) {
		vel.y *= -1;
	}
	else if (pos.y >= ofGetHeight()) {
		vel.y *= -1;
	}
}

void bird::draw() {
    
	ofSetColor(ourColor);
    ofDrawEllipse(pos, head, Size);

}
