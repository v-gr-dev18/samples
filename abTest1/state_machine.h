#pragma once
#ifndef _state_machine_h_
#define _state_machine_h_

class state_machine
{
public:
	state_machine();
	void init(char*);
	void input_char();
	void get_last_word(char*&, int&);
	enum states { BEGIN, END, WORD_START, WORD_KEEP, BLANK_WORD_TO_LEFT, END_WORD_TO_LEFT, BLANK_KEEP, states_bound };
	enum char_class { ZERO, BLANK, WORD, char_class_bound };
	states get_state();
	states get_previous_state();

private:
	char *head;
	char *word_begin;
	size_t word_length;
	states state;
	states previous_state;

	static const char word_chars[];
	static char_class char_to_class[];
	static bool init_flag;
};

#endif