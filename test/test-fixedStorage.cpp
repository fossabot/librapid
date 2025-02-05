#include <librapid>
#include <catch2/catch_test_macros.hpp>
#include <catch2/generators/catch_generators.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>

namespace lrc = librapid;

#define REGISTER_CASES(TYPE)                                                                       \
	SECTION("Type: " STRINGIFY(TYPE)) {                                                            \
		using ScalarType = TYPE;                                                                   \
		lrc::FixedStorage<ScalarType, 9> storage;                                                  \
                                                                                                   \
		REQUIRE(storage.size() == 9);                                                              \
                                                                                                   \
		storage[0] = 1;                                                                            \
		storage[1] = 10;                                                                           \
                                                                                                   \
		REQUIRE(storage[0] == 1);                                                                  \
		REQUIRE(storage[1] == 10);                                                                 \
                                                                                                   \
		lrc::FixedStorage<ScalarType, 10> storage2({1, 2, 3, 4, 5, 6, 7, 8, 9, 10});               \
                                                                                                   \
		REQUIRE(storage2.size() == 10);                                                            \
		REQUIRE(storage2[0] == 1);                                                                 \
		REQUIRE(storage2[1] == 2);                                                                 \
		REQUIRE(storage2[8] == 9);                                                                 \
		REQUIRE(storage2[9] == 10);                                                                \
                                                                                                   \
		lrc::FixedStorage<ScalarType, 20> storage3(1);                                             \
                                                                                                   \
		REQUIRE(storage3.size() == 20);                                                            \
		REQUIRE(storage3[0] == 1);                                                                 \
		REQUIRE(storage3[1] == 1);                                                                 \
		REQUIRE(storage3[18] == 1);                                                                \
		REQUIRE(storage3[19] == 1);                                                                \
                                                                                                   \
		auto storage4 = lrc::FixedStorage<ScalarType, 10>(storage2);                               \
                                                                                                   \
		REQUIRE(storage4.size() == 10);                                                            \
		REQUIRE(storage4[0] == 1);                                                                 \
		REQUIRE(storage4[1] == 2);                                                                 \
		REQUIRE(storage4[8] == 9);                                                                 \
		REQUIRE(storage4[9] == 10);                                                                \
                                                                                                   \
		SECTION("Const Iterator") {                                                                \
			ScalarType i = 1;                                                                      \
			for (const auto &val : storage2) {                                                     \
				REQUIRE(val == i);                                                                 \
				i += 1;                                                                            \
			}                                                                                      \
		}                                                                                          \
                                                                                                   \
		SECTION("Non-Const Iterator") {                                                            \
			ScalarType i = 1;                                                                      \
			for (auto &val : storage2) {                                                           \
				REQUIRE(val == i);                                                                 \
				val += 1;                                                                          \
				i += 1;                                                                            \
			}                                                                                      \
		}                                                                                          \
	}

#define BENCHMARK_CONSTRUCTORS(TYPE_, FILL_)                                                       \
	BENCHMARK("FixedStorage<" STRINGIFY(TYPE_) "> 10") {                                           \
		lrc::FixedStorage<TYPE_, 10> storage;                                                      \
		return storage.size();                                                                     \
	};                                                                                             \
                                                                                                   \
	BENCHMARK("FixedStorage<" STRINGIFY(TYPE_) "> 1000") {                                         \
		lrc::FixedStorage<TYPE_, 1000> storage;                                                    \
		return storage.size();                                                                     \
	};                                                                                             \
                                                                                                   \
	BENCHMARK("FixedStorage<" STRINGIFY(TYPE_) "> 1000000") {                                      \
		lrc::FixedStorage<TYPE_, 1000000> storage;                                                 \
		return storage.size();                                                                     \
	};                                                                                             \
                                                                                                   \
	BENCHMARK("FixedStorage<" STRINGIFY(TYPE_) "> 10 FILLED") {                                    \
		lrc::FixedStorage<TYPE_, 10> storage(FILL_);                                               \
		return storage.size();                                                                     \
	};                                                                                             \
                                                                                                   \
	BENCHMARK("FixedStorage<" STRINGIFY(TYPE_) "> 1000 FILLED") {                                  \
		lrc::FixedStorage<TYPE_, 1000> storage(FILL_);                                             \
		return storage.size();                                                                     \
	};                                                                                             \
                                                                                                   \
	BENCHMARK("FixedStorage<" STRINGIFY(TYPE_) "> 1000000 FILLED") {                               \
		lrc::FixedStorage<TYPE_, 1000000> storage(FILL_);                                          \
		return storage.size();                                                                     \
	}

TEST_CASE("Test FixedStorage<T>", "[fixed-storage]") {
	SECTION("Trivially Constructible Storage") {
		REGISTER_CASES(char);
		REGISTER_CASES(unsigned char);
		REGISTER_CASES(short);
		REGISTER_CASES(unsigned short);
		REGISTER_CASES(int);
		REGISTER_CASES(unsigned int);
		REGISTER_CASES(long);
		REGISTER_CASES(unsigned long);
		REGISTER_CASES(long long);
		REGISTER_CASES(unsigned long long);
		REGISTER_CASES(float);
		REGISTER_CASES(double);
		REGISTER_CASES(long double);
	}

	SECTION("Non-Trivially Constructible Storage") {
		// Can't use normal tests, so just test a few things
		lrc::FixedStorage<std::string, 5> storage;
		REQUIRE(storage.size() == 5);
		storage[0] = "Hello";
		storage[1] = "World";
		REQUIRE(storage[0] == "Hello");
		REQUIRE(storage[1] == "World");

		lrc::FixedStorage<std::string, 2> storage2({"Hello", "World"});
		REQUIRE(storage2.size() == 2);
		REQUIRE(storage2[0] == "Hello");
		REQUIRE(storage2[1] == "World");

		lrc::FixedStorage<std::string, 20> storage3("Hello");
		REQUIRE(storage3.size() == 20);
		REQUIRE(storage3[0] == "Hello");
		REQUIRE(storage3[1] == "Hello");
		REQUIRE(storage3[18] == "Hello");
		REQUIRE(storage3[19] == "Hello");

		auto storage4 = lrc::FixedStorage<std::vector<std::string>, 10>();
		REQUIRE(storage4.size() == 10);
		storage4[0].push_back("Hello");
		storage4[0].push_back("World");
		REQUIRE(storage4[0][0] == "Hello");
		REQUIRE(storage4[0][1] == "World");

		struct Three {
			int a;
			int b;
			int c;
		};

		auto storage5 = lrc::FixedStorage<Three, 10>();
		REQUIRE(storage5.size() == 10);
		storage5[0].a = 1;
		storage5[0].b = 2;
		storage5[0].c = 3;
		storage5[1].a = 4;
		storage5[1].b = 5;
		storage5[1].c = 6;
		REQUIRE(storage5[0].a == 1);
		REQUIRE(storage5[0].b == 2);
		REQUIRE(storage5[0].c == 3);
		REQUIRE(storage5[1].a == 4);
		REQUIRE(storage5[1].b == 5);
		REQUIRE(storage5[1].c == 6);

		auto storage6 = storage5;
		REQUIRE(storage5[0].a == 1);
		REQUIRE(storage5[0].b == 2);
		REQUIRE(storage5[0].c == 3);
		REQUIRE(storage5[1].a == 4);
		REQUIRE(storage5[1].b == 5);
		REQUIRE(storage5[1].c == 6);
	}

	SECTION("Benchmarks") {
		BENCHMARK_CONSTRUCTORS(int, 123);
		BENCHMARK_CONSTRUCTORS(double, 456);
		BENCHMARK_CONSTRUCTORS(std::string, "Hello, World");
		BENCHMARK_CONSTRUCTORS(std::vector<int>, {1 COMMA 2 COMMA 3 COMMA 4});
		BENCHMARK_CONSTRUCTORS(std::vector<double>, {1 COMMA 2 COMMA 3 COMMA 4});
	}
}
