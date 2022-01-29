/*
** EPITECH PROJECT, 2020
** cpp_rush3_2019
** File description:
** IMonitorModule
*/

#ifndef IMONITORMODULE_HPP_
#define IMONITORMODULE_HPP_

class IMonitorModule {
	public:
		IMonitorModule(){};
		virtual ~IMonitorModule(){};
        virtual bool refresh() = 0;
        virtual void setCommandDisplay(char command) = 0;
        virtual char getCommandDisplay() const = 0;
        virtual bool isDisplay() const = 0;
        virtual void setDislay(bool display) = 0;
	protected:
	private:
};

#endif /* !IMONITORMODULE_HPP_ */
