// Bitwise.cpp
// version 1.1
//

#include "stdafx.h"

// sorry Mac users, please use Windows if you want to use my game loop
#include <windows.h>

// Bitset is only being used to print the final values
#include <bitset>
#include <iostream>

//=============================================================
//=============================================================

// 
// SDL is a common library used for input detection
// these are some scancodes from this list: https://wiki.libsdl.org/SDL_Keycode
//

const int SDL_SCANCODE_LCTRL = 1241;
const int SDL_SCANCODE_SPACE = 636;
const int SDL_SCANCODE_LSHIFT = 55;
const int SDL_SCANCODE_BACKSPACE = 13;
const int SDL_SCANCODE_UP = 44;
const int SDL_SCANCODE_DOWN = 52;
const int SDL_SCANCODE_E = 6223;

// Created the switches
enum Actions
{
	ATTACK = 1 << 0,	// 0000 0001
	JUMP = 1 << 1,		// 0000 0010
	DUCK = 1 << 2,		// 0000 0100
	FORWARD = 1 << 3,	// 0000 1000
	BACK = 1 << 4,		// 0001 0000
	USE = 1 << 5,		// 0010 0000
	CANCEL = 1 << 6		// 0100 0000
};

//=============================================================
//=============================================================

class InputState
{
public:

	// the "friend" keyword allows you to bypass encapsulation
	// in this case, it allows InputManager to reach into my private variables
	friend class InputManager;

	InputState();
	~InputState();

	bool IsAttack() const;
	bool IsJump() const;
	bool IsDuck() const;
	bool IsForward() const;
	bool IsBack() const;
	bool IsUse() const;
	bool IsCancel() const;

private:
	// Contairner of all the actions
	int mAction;

};

//=============================================================
//=============================================================

InputState::InputState()
{
	mAction = 0; // 0000 0000
}

InputState::~InputState()
{
}

// Check if the bits match every single action requested
bool InputState::IsAttack() const
{
	return (mAction & ATTACK) != 0;
}

bool InputState::IsJump() const
{
	return (mAction & JUMP) != 0;
}

bool InputState::IsDuck() const
{
	return (mAction & DUCK) != 0;
}

bool InputState::IsForward() const
{
	return (mAction & FORWARD) != 0;
}

bool InputState::IsBack() const
{
	return (mAction & BACK) != 0;
}

bool InputState::IsUse() const
{
	return (mAction & USE) != 0;
}

bool InputState::IsCancel() const
{
	return (mAction & CANCEL) != 0;
}

//=============================================================
//=============================================================

class InputManager
{
public:

	// this gets called each frame to query the system for the button states
	void Update();

	// Added the test var to change the actions
	bool IsButtonDown(int nScancode, int testVar) const;

	const InputState& GetState() const { mState; }

private:

	InputState mState;

};

//=============================================================
//=============================================================

void InputManager::Update()
{

	// Simulating the inputs and if the button is being pressed, it should shift the bits in the int variable
	bool attacking = IsButtonDown(SDL_SCANCODE_LCTRL, 1);
	if (attacking) {
		mState.mAction |= ATTACK;
	}

	bool jumping = IsButtonDown(SDL_SCANCODE_SPACE, 1);
	if (jumping) {
		mState.mAction |= JUMP;
	}

	bool ducking = IsButtonDown(SDL_SCANCODE_LSHIFT, 0);
	if (ducking) {
		mState.mAction |= DUCK;
	}

	bool forward = IsButtonDown(SDL_SCANCODE_UP, 1);
	if (forward) {
		mState.mAction |= FORWARD;
	}

	bool back = IsButtonDown(SDL_SCANCODE_DOWN, 0);
	if (back) {
		mState.mAction |= BACK;
	}

	bool use = IsButtonDown(SDL_SCANCODE_E, 1);
	if (use) {
		mState.mAction |= USE;
	}

	bool cancel = IsButtonDown(SDL_SCANCODE_BACKSPACE, 0);
	if (cancel) {
		mState.mAction |= CANCEL;
	}

	// Just added the library to check the final outcome
	std::bitset<7> bitset1;
	bitset1 = mState.mAction;
	std::cout << bitset1 << std::endl;
	std::cin.get();
}

bool InputManager::IsButtonDown(int nScancode, int testVar) const
{
	return testVar == 1 ? false : true;
}

//=============================================================
//=============================================================

int main()
{
	// my VERY simple game loop
	InputManager inputManager;

	while (true)
	{
		inputManager.Update();

		Sleep(100); // don't burn the CPU
	}

	return 0;
}