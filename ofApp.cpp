#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(30);
	ofSetWindowTitle("openFrameworks");

	ofBackground(39);
	ofSetColor(255);
}

//--------------------------------------------------------------
void ofApp::update() {

	ofSeedRandom(39);
}

//--------------------------------------------------------------
void ofApp::draw() {

	ofTranslate(ofGetWindowSize() * 0.5);

	auto radius = 50;

	for (int y = -280; y <= 280; y += 140) {

		auto deg_param = ofMap(y, -280, 280, 0, 180);

		for (int deg = 0; deg < 360; deg += 20) {

			vector<glm::vec2> vertices;
			auto tmp_deg = deg + ofGetFrameNum() * 1;

			for (int x = -200; x <= 200; x += 400) {

				auto vertex = glm::vec2(x + radius * cos(tmp_deg * DEG_TO_RAD), y + radius * sin(tmp_deg * DEG_TO_RAD));
				vertices.push_back(vertex);
				tmp_deg += deg_param;
			}

			ofNoFill();
			ofBeginShape();
			ofVertices(vertices);
			ofEndShape();

			
			for (auto& vertex : vertices) {

				ofFill();
				ofDrawCircle(vertex, 2);

				ofNoFill();
				ofDrawCircle(vertex, 5);
			}
		}
	}
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}