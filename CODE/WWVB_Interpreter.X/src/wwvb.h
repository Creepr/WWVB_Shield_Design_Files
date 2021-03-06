/*------------------------------------------------------------------------------
 *  ______     __  __     ______     ______     __   __     ______
 * /\  ___\   /\ \_\ \   /\  == \   /\  __ \   /\ "-.\ \   /\  __ \
 * \ \ \____  \ \  __ \  \ \  __<   \ \ \/\ \  \ \ \-.  \  \ \ \/\ \
 *  \ \_____\  \ \_\ \_\  \ \_\ \_\  \ \_____\  \ \_\\"\_\  \ \_____\
 *   \/_____/   \/_/\/_/   \/_/ /_/   \/_____/   \/_/ \/_/   \/_____/
 *          ______   ______     __    __     __     ______
 *         /\__  _\ /\  __ \   /\ "-./  \   /\ \   /\  ___\
 *         \/_/\ \/ \ \ \/\ \  \ \ \-./\ \  \ \ \  \ \ \____
 *            \ \_\  \ \_____\  \ \_\ \ \_\  \ \_\  \ \_____\
 *             \/_/   \/_____/   \/_/  \/_/   \/_/   \/_____/
 *
 * --- WWVB Interpreter Header ---
 * Authors: Eric Born and Josh Friend
 * Course: EGR326-901
 * Instructor: Dr. Andrew Sterian
 * Date: Dec 8, 2011
 -----------------------------------------------------------------------------*/

#ifndef WWVB_h
#define WWVB_h

#include "types.h"

//WWVB decoding algorithm parameters
#define MAX_EDGES 7             //Must be at least 1
#define MIN_BIT_WIDTH_MS 975    //Minimum bit width
#define BIT_TIMEOUT_MS 1100     //Bit width decode timout value

//Define WWVB Pulse widths
#define MAX_ERROR 100
#define MAX_FRAME 900
#define MAX_ONE 600
#define MAX_ZERO 300

#define BIT_LEN_ZERO_MS 200
#define BIT_LEN_ONE_MS 500
#define BIT_LEN_FRAME_MS 800
#define MARGIN_MS 150

//Definitions of values returned by bit_value()
#define ERROR 3
#define FRAME 2
#define ONE 1
#define ZERO 0

//Global flag to mark when valid WWVB frame has been recieved
extern uint8_t frame_recieved_flag;

//Lookup table of dont care bits
//DUT and leapsecond not used
static const uint8_t dont_care_bit[60] = {0,0,0,0,1,0,0,0,0,0,  //9
                                          1,1,0,0,1,0,0,0,0,0,  //19
                                          1,1,0,0,1,0,0,0,0,0,  //29
                                          0,0,0,0,1,1,0,1,1,1,  //39
                                          1,1,1,1,1,0,0,0,0,0,  //49
                                          0,0,0,0,1,0,1,0,0,0}; //59

//Lookup table of frame marker bits
static const uint8_t frame_bit[60] = {1,0,0,0,0,0,0,0,0,1,  //9
                                      0,0,0,0,0,0,0,0,0,1,  //19
                                      0,0,0,0,0,0,0,0,0,1,  //29
                                      0,0,0,0,0,0,0,0,0,1,  //39
                                      0,0,0,0,0,0,0,0,0,1,  //49
                                      0,0,0,0,0,0,0,0,0,1}; //59

//Function prototypes
uint8_t process_bit(uint16_t pulse_length);
uint8_t get_bit_value(uint16_t pulse_length);
void process_frame(time_t *frame);
void clear_data(time_t *frame);

#endif