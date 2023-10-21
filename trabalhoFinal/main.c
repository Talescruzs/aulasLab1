#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>
#include <allegro5/keyboard.h>

int main (){

  al_init();
  al_init_font_addon();
  al_init_image_addon();
  al_install_keyboard();

  ALLEGRO_DISPLAY * display = al_create_display(726, 806);
  al_set_window_position(display, 100, 100);
  al_set_window_title(display, "surakarta");

  ALLEGRO_FONT* font = al_create_builtin_font();
  ALLEGRO_TIMER* timer = al_create_timer(1.0 / 60.0);

  ALLEGRO_BITMAP * bg = al_load_bitmap("./img/fundo.png");
  ALLEGRO_BITMAP * peca = al_load_bitmap("./img/peca1.png");

  ALLEGRO_EVENT_QUEUE * event_queue = al_create_event_queue();
  al_register_event_source(event_queue, al_get_display_event_source(display));
  al_register_event_source(event_queue, al_get_timer_event_source(timer));
  al_register_event_source(event_queue, al_get_keyboard_event_source() );
  al_start_timer(timer);

  while(true){
    ALLEGRO_EVENT event;
    al_wait_for_event(event_queue, &event);
    if( event.type == ALLEGRO_EVENT_DISPLAY_CLOSE ){
      break;
    }

    al_draw_bitmap(bg, 0, 0, 0);
    for(int i = 0; i<6; i++){
      for(int j = 0; j<6; j++){
        al_draw_bitmap(peca, 140+(i*76), 150+(j*85), 0);
      }
    }
    al_flip_display();
  }

  al_destroy_bitmap(bg);
  al_destroy_bitmap(peca);
  al_destroy_font(font);
  al_destroy_display(display);
  al_destroy_event_queue(event_queue);

  return 0;
}