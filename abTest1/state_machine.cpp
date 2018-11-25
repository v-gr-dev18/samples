#include "pch.h"
#include <limits.h>
#include <string.h>
#include "state_machine.h"


const char state_machine::word_chars[] = "!""#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~";
bool state_machine::init_flag = false;
state_machine::char_class state_machine::char_to_class[UCHAR_MAX + 1];

state_machine::state_machine()
{
	head = word_begin = NULL;
	word_length = -1;
	state = END;
	previous_state = END;

	if (init_flag) return;
	for (int i = 1; i <= UCHAR_MAX; ++i) char_to_class[i] = BLANK;
	int word_chars_length = strlen(word_chars);
	for (int i = 0; i < word_chars_length; ++i) char_to_class[word_chars[i]] = WORD;
	char_to_class[0] = ZERO;
	init_flag = true;
}
void state_machine::init(char* str)
{
	state_machine();
	head = str;
	state = BEGIN;
}

void state_machine::input_char()
{
	static states state_table[states_bound][char_class_bound] =
		/* 012345678901234567      0123456789012345, 012345678901234567, 0123456789 */
		/*                                     ZERO,              BLANK,       WORD */
	{   /* BEGIN              */ {              END,         BLANK_KEEP, WORD_START }
	,   /* END                */ {              END,                END,        END }
	,   /* WORD_START         */ { END_WORD_TO_LEFT, BLANK_WORD_TO_LEFT,  WORD_KEEP }
	,   /* WORD_KEEP          */ { END_WORD_TO_LEFT, BLANK_WORD_TO_LEFT,  WORD_KEEP }
	,   /* BLANK_WORD_TO_LEFT */ {              END,         BLANK_KEEP, WORD_START }
	,   /* END_WORD_TO_LEFT   */ {              END,                END,        END }
	,   /* BLANK_KEEP         */ {              END,         BLANK_KEEP, WORD_START }
	};  /* 012345678901234567      0123456789012345, 012345678901234567, 0123456789 */
	if (head == NULL) return;
	previous_state = state;
	if (BEGIN != previous_state) ++head;
	state = state_table[previous_state][char_to_class[*head]];
	switch (state)
	{
	case WORD_START: word_length = 1; word_begin = head; break;
	case WORD_KEEP: ++word_length; break;
	}
}

void state_machine::get_last_word(char *&w, int &l) { w = word_begin; l = word_length; }
state_machine::states state_machine::get_state() { return state; }
state_machine::states state_machine::get_previous_state() { return previous_state; }
