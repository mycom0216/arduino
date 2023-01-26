#define C 261
#define C_SHARP 277
#define D 294
#define D_SHARP 311
#define E 330
#define F 350
#define F_SHARP 370
#define G 391
#define G_SHARP 416
#define A 440
#define A_SHARP 467
#define B 493
#define C 261











int scale[] = { 0, 261, 294, 330, 349, 392, 440, 494};
int melody[] = {1, 3, 5, 1, 3, 5, 6, 6, 6, 5};


void setup() {}

void loop() {
  // tone(핀 번호, 진동수, 지속시간)  

  // for (int i = 0; i < sizeof(scale) / sizeof(int); i++) {
    // tone(8, scale[i], 200);
    // delay(400);

    for(int i = 0; i < sizeof(melody) / sizeof(int); i++) {

      tone(8, scale[melody[i]], 200);
      delay(400);

    }
}


