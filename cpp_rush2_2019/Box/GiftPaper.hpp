/*
** EPITECH PROJECT, 2020
** CPPool_2019
** File description:
** GiftPaper
*/

#ifndef GIFTPAPER_HPP_
#define GIFTPAPER_HPP_

#include "Wrap.hpp"

class GiftPaper: public Wrap {
	public:
		GiftPaper();
		~GiftPaper();
        void wrapMeThat(const Object *obj);

	protected:
	private:
};

#endif /* !GIFTPAPER_HPP_ */