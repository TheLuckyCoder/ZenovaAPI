#pragma once

namespace Bedrock {
	class IItem {
		IItem() = default;
		IItem(const IItem&) = default;
		IItem(IItem&&) = default;
		virtual ~IItem() = default;

		IItem &operator=(const IItem&) = default;
		IItem &operator=(IItem&&) noexcept = default;
	};
}
