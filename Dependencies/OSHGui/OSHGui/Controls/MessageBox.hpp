/*
 * OldSchoolHack GUI
 *
 * by KN4CK3R http://www.oldschoolhack.me
 *
 * See license in OSHGui.hpp
 */

#ifndef OSHGUI_CONTROLS_MESSAGEBOX_HPP
#define OSHGUI_CONTROLS_MESSAGEBOX_HPP

#include <functional>
#include <vector>
#include "Form.hpp"
#include "../Misc/Strings.hpp"

#ifdef _MSC_VER
#ifdef MessageBox
#undef MessageBox
#endif
#endif

namespace OSHGui {
	/**
	 * Gibt Konstanten an, die definieren, welche Schaltfl�chen der MessageBox angezeigt werden.
	 */
	enum class MessageBoxButtons {
		/**
		 * Das Meldungsfeld enth�lt die Schaltfl�che OK.
		 */
		OK,
		/**
		 * Das Meldungsfeld enth�lt die Schaltfl�chen OK und Abbrechen.
		 */
		OKCancel,
		/**
		 * Das Meldungsfeld enth�lt die Schaltfl�chen Abbrechen, Wiederholen und Ignorieren.
		 */
		AbortRetryIgnore,
		/**
		 * Das Meldungsfeld enth�lt die Schaltfl�chen Ja und Nein.
		 */
		YesNo,
		/**
		 * Das Meldungsfeld enth�lt die Schaltfl�chen Ja, Nein und Abbrechen.
		 */
		YesNoCancel,
		/**
		 * Das Meldungsfeld enth�lt die Schaltfl�chen Wiederholen und Abbrechen.
		 */
		RetryCancel
	};

	class OSHGUI_EXPORT MessageBox {
	public:
		static void Show(const Misc::UnicodeString &text);
		static void Show(const Misc::UnicodeString &text, const Misc::UnicodeString &caption);
		static void Show(const Misc::UnicodeString &text, const Misc::UnicodeString &caption, MessageBoxButtons buttons);
		static void ShowDialog(const Misc::UnicodeString &text, const std::function<void(DialogResult result)> &closeFunction);
		static void ShowDialog(const Misc::UnicodeString &text, const Misc::UnicodeString &caption, const std::function<void(DialogResult result)> &closeFunction);
		static void ShowDialog(const Misc::UnicodeString &text, const Misc::UnicodeString &caption, MessageBoxButtons buttons, const std::function<void(DialogResult result)> &closeFunction);

	public:
		class MessageBoxForm : public Form {
		private:
			void InitializeComponent(const Misc::UnicodeString &text, const Misc::UnicodeString &caption, MessageBoxButtons buttons);
			void AddButtons(const std::vector<Misc::UnicodeString> &label, const std::vector<ClickEventHandler> &eventHandler);

		public:
			MessageBoxForm(const Misc::UnicodeString &text, const Misc::UnicodeString &caption, MessageBoxButtons buttons);
		};
	};
}

#endif