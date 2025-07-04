#define ILI9488_DRIVER

#define TFT_CS   0     // D3 = GPIO0
#define TFT_DC   15    // D8 = GPIO15
#define TFT_RST  -1    // если RST не подключён
#define TFT_MOSI 13    // D7 = GPIO13
#define TFT_SCLK 14    // D5 = GPIO14
#define TFT_MISO -1 

#define LOAD_GLCD
#define LOAD_FONT2
#define LOAD_FONT4
#define LOAD_FONT6
#define LOAD_FONT7
#define LOAD_FONT8

#define SPI_FREQUENCY  27000000
