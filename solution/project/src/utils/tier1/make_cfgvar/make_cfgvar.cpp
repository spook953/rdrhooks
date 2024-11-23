#include "make_cfgvar.hpp"

void CFGVar::save(std::string_view path)
{
	std::ofstream file{ path.data() };

	if (!file.is_open()) {
		return;
	}

	nlohmann::json j{};

	for (CFGVar *const var : getInsts<CFGVar>())
	{
		try
		{
			if (var->hash() == typeid(bool).hash_code()) {
				j[var->name()] = *static_cast<bool *>(var->ptr());
			}

			else if (var->hash() == typeid(int).hash_code()) {
				j[var->name()] = *static_cast<int *>(var->ptr());
			}

			else if (var->hash() == typeid(float).hash_code()) {
				j[var->name()] = *static_cast<float *>(var->ptr());
			}

			else if (var->hash() == typeid(std::string).hash_code()) {
				j[var->name()] = *static_cast<std::string *>(var->ptr());
			}

			else {
				con::printWrn(std::format("failed to save {} (unknown type)", var->name()));
			}
		}

		catch (const std::exception &e) {
			con::printWrn(std::format("failed to save {} ({})", var->name(), e.what()));
		}
	}

	file << std::setw(4) << j;
}

void CFGVar::load(std::string_view path)
{
	std::ifstream file{ path.data() };

	if (!file.is_open()) {
		return;
	}

	nlohmann::json j{};

	file >> j;

	for (CFGVar *const var : getInsts<CFGVar>())
	{
		try
		{
			if (j.contains(var->name()))
			{
				const size_t type{ var->hash() };

				if (type == typeid(bool).hash_code()) {
					*static_cast<bool *>(var->ptr()) = j[var->name()];
				}

				else if (type == typeid(int).hash_code()) {
					*static_cast<int *>(var->ptr()) = j[var->name()];
				}

				else if (type == typeid(float).hash_code()) {
					*static_cast<float *>(var->ptr()) = j[var->name()];
				}

				else if (type == typeid(std::string).hash_code()) {
					*static_cast<std::string *>(var->ptr()) = j[var->name()];
				}

				else {
					con::printWrn(std::format("failed to load {} (unknown type)", var->name()));
				}
			}

			else {
				con::printWrn(std::format("failed to load {} (not found)", var->name()));
			}
		}

		catch (const std::exception &e) {
			con::printWrn(std::format("failed to load {} ({})", var->name(), e.what()));
		}
	}
}