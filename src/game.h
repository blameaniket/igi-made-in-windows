#ifndef GAME_H
#define GAME_H

void game_run(int argc, char *argv[]);

void _game_init();
void _game_shutdown();
void _game_on_update();
void _game_on_render();

#endif // GAME_H
