#include "dante.h"
#include "bolt.h"

void
light_stuff () {
	//
}

void
heavy_stuff () {
	//
}

int
main (int argc, char const *argv[])
{
	Bolt bolt = bolt_new_bolt("Dante");
	bolt_add_milestone ("start");

	bolt_add_action (light_stuff, "light_stuff", 1000);
	bolt_add_experiment (heavy_stuff, "heavy_stuff", 10);
	bolt_add_milestone ("setup complete");

	bolt_run();
	bolt_add_milestone ("run complete");

	bolt_print();
	return 0;
}
