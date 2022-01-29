/*
** EPITECH PROJECT, 2020
** cpp_d14m_2019
** File description:
** Mixer
*/

#pragma once

#include "MixerBase.hpp"

class Mixer : public MixerBase {
	public:
		Mixer();
		~Mixer();
        int mix(FruitBox &fruits) const;
        void setPlug(bool plug);
	protected:
	private:
};