#include "Stand.h"

int main(int argc, char* argv[]) {
	Engine* engine = new ICEngine;
	Stand stand;
	stand.run(engine);
	delete engine;
	return 0;
}