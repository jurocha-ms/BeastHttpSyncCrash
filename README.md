This is a proof of concept of a bug found when using Boost/Beast HTTP features on Windows building with MSVC.

# System requirements

- Microsoft Visual Studio 2019 or 2017
  - Workloads
    - **Desktop development with C++**
  - Individual components
    - Compilers, build tools and runtimes
      - **MSVC v141 - VS 2017 C++ x64/x86 build tools (v14.16)**
    - SDKs, libraries and frameworks
      - **Windows 10 SDK (10.0.18362.0)**

# Steps to reproduce

1. Clone this repository.
1. Open `BeastHttpSyncCrash.sln`.
1. Build the solution for `Release|x86`.
1. Run project `Vc141Boost171`.

# Expected behavior

Program runs and exits silently

# Actual behavior

Program crashes with the following exception:
```
Vc141Boost171.exe has triggered a breakpoint.
```

Source:
```
packages\boost.1.71.0.0\lib\native\include\boost\beast\core\impl\buffers_cat.hpp
```

Stack trace
```
Vc141Boost171.exe!boost::beast::buffers_cat_view<boost::beast::detail::buffers_ref<boost::beast::buffers_cat_view<boost::asio::const_buffer,boost::asio::const_buffer,boost::asio::const_buffer,boost::beast::http::basic_fields<std::allocator<char>>::writer::field_range,boost::beast::http::chunk_crlf>>,boost::asio::const_buffer>::const_iterator::increment::operator()(std::integral_constant<unsigned int,3> __formal) Line 269	C++
  [Inline Frame] Vc141Boost171.exe!boost::mp11::detail::mp_with_index_impl_<4>::call(unsigned int) Line 114	C++
  [Inline Frame] Vc141Boost171.exe!boost::mp11::mp_with_index(unsigned int) Line 382	C++
  Vc141Boost171.exe!boost::beast::buffers_cat_view<boost::beast::detail::buffers_ref<boost::beast::buffers_cat_view<boost::asio::const_buffer,boost::asio::const_buffer,boost::asio::const_buffer,boost::beast::http::basic_fields<std::allocator<char>>::writer::field_range,boost::beast::http::chunk_crlf>>,boost::asio::const_buffer>::const_iterator::operator++() Line 396	C++
  [Inline Frame] Vc141Boost171.exe!boost::beast::buffers_suffix<boost::beast::buffers_cat_view<boost::beast::detail::buffers_ref<boost::beast::buffers_cat_view<boost::asio::const_buffer,boost::asio::const_buffer,boost::asio::const_buffer,boost::beast::http::basic_fields<std::allocator<char>>::writer::field_range,boost::beast::http::chunk_crlf>>,boost::asio::const_buffer>>::const_iterator::operator++() Line 84	C++
  [Inline Frame] Vc141Boost171.exe!boost::beast::buffers_suffix<boost::beast::buffers_cat_view<boost::beast::detail::buffers_ref<boost::beast::buffers_cat_view<boost::asio::const_buffer,boost::asio::const_buffer,boost::asio::const_buffer,boost::beast::http::basic_fields<std::allocator<char>>::writer::field_range,boost::beast::http::chunk_crlf>>,boost::asio::const_buffer>>::const_iterator::operator++(int) Line 92	C++
  Vc141Boost171.exe!boost::beast::buffers_prefix_view<boost::beast::buffers_suffix<boost::beast::buffers_cat_view<boost::beast::detail::buffers_ref<boost::beast::buffers_cat_view<boost::asio::const_buffer,boost::asio::const_buffer,boost::asio::const_buffer,boost::beast::http::basic_fields<std::allocator<char>>::writer::field_range,boost::beast::http::chunk_crlf>>,boost::asio::const_buffer>> const &>::setup(unsigned int size) Line 153	C++
  [Inline Frame] Vc141Boost171.exe!boost::beast::buffers_prefix_view<boost::beast::buffers_suffix<boost::beast::buffers_cat_view<boost::beast::detail::buffers_ref<boost::beast::buffers_cat_view<boost::asio::const_buffer,boost::asio::const_buffer,boost::asio::const_buffer,boost::beast::http::basic_fields<std::allocator<char>>::writer::field_range,boost::beast::http::chunk_crlf>>,boost::asio::const_buffer>> const &>::{ctor}(unsigned int) Line 216	C++
  [Inline Frame] Vc141Boost171.exe!boost::beast::detail::variant<boost::beast::buffers_prefix_view<boost::beast::buffers_suffix<boost::beast::detail::buffers_ref<boost::beast::buffers_cat_view<boost::asio::const_buffer,boost::asio::const_buffer,boost::asio::const_buffer,boost::beast::http::basic_fields<std::allocator<char>>::writer::field_range,boost::beast::http::chunk_crlf>>> const &>,boost::beast::buffers_prefix_view<boost::beast::buffers_suffix<boost::beast::buffers_cat_view<boost::beast::detail::buffers_ref<boost::beast::buffers_cat_view<boost::asio::const_buffer,boost::asio::const_buffer,boost::asio::const_buffer,boost::beast::http::basic_fields<std::allocator<char>>::writer::field_range,boost::beast::http::chunk_crlf>>,boost::asio::const_buffer>> const &>,boost::beast::buffers_prefix_view<boost::beast::buffers_suffix<boost::asio::const_buffer> const &>,boost::beast::buffers_prefix_view<boost::beast::buffers_suffix<boost::beast::buffers_cat_view<boost::beast::detail::buffers_ref<boost::beast::buffers_cat_view<boost::asio::const_buffer,boost::asio::const_buffer,boost::asio::const_buffer,boost::beast::http::basic_fields<std::allocator<char>>::writer::field_range,boost::beast::http::chunk_crlf>>,boost::beast::http::detail::chunk_size,boost::asio::const_buffer,boost::beast::http::chunk_crlf,boost::asio::const_buffer,boost::beast::http::chunk_crlf>> const &>,boost::beast::buffers_prefix_view<boost::beast::buffers_suffix<boost::beast::buffers_cat_view<boost::beast::http::detail::chunk_size,boost::asio::const_buffer,boost::beast::http::chunk_crlf,boost::asio::const_buffer,boost::beast::http::chunk_crlf>> const &>,boost::beast::buffers_prefix_view<boost::beast::buffers_suffix<boost::beast::buffers_cat_view<boost::beast::http::detail::chunk_size,boost::asio::const_buffer,boost::beast::http::chunk_crlf,boost::asio::const_buffer,boost::beast::http::chunk_crlf,boost::asio::const_buffer,boost::asio::const_buffer,boost::beast::http::chunk_crlf>> const &>,boost::beast::buffers_prefix_view<boost::beast::buffers_suffix<boost::beast::buffers_cat_view<boost::beast::detail::buffers_ref<boost::beast::buffers_cat_view<boost::asio::const_buffer,boost::asio::const_buffer,boost::asio::const_buffer,boost::beast::http::basic_fields<std::allocator<char>>::writer::field_range,boost::beast::http::chunk_crlf>>,boost::beast::http::detail::chunk_size,boost::asio::const_buffer,boost::beast::http::chunk_crlf,boost::asio::const_buffer,boost::beast::http::chunk_crlf,boost::asio::const_buffer,boost::asio::const_buffer,boost::beast::http::chunk_crlf>> const &>,boost::beast::buffers_prefix_view<boost::beast::buffers_suffix<boost::beast::buffers_cat_view<boost::asio::const_buffer,boost::asio::const_buffer,boost::beast::http::chunk_crlf>> const &>>::emplace(unsigned int &) Line 199	C++
  Vc141Boost171.exe!boost::beast::http::serializer<1,boost::beast::http::basic_string_body<char,std::char_traits<char>,std::allocator<char>>,boost::beast::http::basic_fields<std::allocator<char>>>::do_visit<2,boost::beast::http::detail::write_some_lambda<boost::beast::basic_stream<boost::asio::ip::tcp,boost::asio::executor,boost::beast::unlimited_rate_policy>>>(boost::system::error_code & ec, boost::beast::http::detail::write_some_lambda<boost::beast::basic_stream<boost::asio::ip::tcp,boost::asio::executor,boost::beast::unlimited_rate_policy>> & visit) Line 52	C++
  Vc141Boost171.exe!boost::beast::http::serializer<1,boost::beast::http::basic_string_body<char,std::char_traits<char>,std::allocator<char>>,boost::beast::http::basic_fields<std::allocator<char>>>::next<boost::beast::http::detail::write_some_lambda<boost::beast::basic_stream<boost::asio::ip::tcp,boost::asio::executor,boost::beast::unlimited_rate_policy>> &>(boost::system::error_code & ec, boost::beast::http::detail::write_some_lambda<boost::beast::basic_stream<boost::asio::ip::tcp,boost::asio::executor,boost::beast::unlimited_rate_policy>> & visit) Line 111	C++
  [Inline Frame] Vc141Boost171.exe!boost::beast::http::detail::write_some_impl(boost::beast::basic_stream<boost::asio::ip::tcp,boost::asio::executor,boost::beast::unlimited_rate_policy> &) Line 452	C++
  [Inline Frame] Vc141Boost171.exe!boost::beast::http::write_some(boost::beast::basic_stream<boost::asio::ip::tcp,boost::asio::executor,boost::beast::unlimited_rate_policy> &) Line 523	C++
  Vc141Boost171.exe!boost::beast::http::write<boost::beast::basic_stream<boost::asio::ip::tcp,boost::asio::executor,boost::beast::unlimited_rate_policy>,1,boost::beast::http::basic_string_body<char,std::char_traits<char>,std::allocator<char>>,boost::beast::http::basic_fields<std::allocator<char>>>(boost::beast::basic_stream<boost::asio::ip::tcp,boost::asio::executor,boost::beast::unlimited_rate_policy> & stream, boost::beast::http::serializer<1,boost::beast::http::basic_string_body<char,std::char_traits<char>,std::allocator<char>>,boost::beast::http::basic_fields<std::allocator<char>>> & sr, boost::system::error_code & ec) Line 671	C++
  [Inline Frame] Vc141Boost171.exe!boost::beast::http::write(boost::beast::basic_stream<boost::asio::ip::tcp,boost::asio::executor,boost::beast::unlimited_rate_policy> &) Line 798	C++
  Vc141Boost171.exe!boost::beast::http::write<boost::beast::basic_stream<boost::asio::ip::tcp,boost::asio::executor,boost::beast::unlimited_rate_policy>,1,boost::beast::http::basic_string_body<char,std::char_traits<char>,std::allocator<char>>,boost::beast::http::basic_fields<std::allocator<char>>>(boost::beast::basic_stream<boost::asio::ip::tcp,boost::asio::executor,boost::beast::unlimited_rate_policy> & stream, const boost::beast::http::message<1,boost::beast::http::basic_string_body<char,std::char_traits<char>,std::allocator<char>>,boost::beast::http::basic_fields<std::allocator<char>>> & msg) Line 753	C++
  Vc141Boost171.exe!main() Line 33	C++
  [Inline Frame] Vc141Boost171.exe!invoke_main() Line 78	C++
  Vc141Boost171.exe!__scrt_common_main_seh() Line 288	C++
  kernel32.dll!BaseThreadInitThunk(unsigned long RunProcessInit, long(__stdcall*)(void *) StartAddress, void * Argument) Line 64	C
  ntdll.dll!__RtlUserThreadStart(long(__stdcall*)(void *) StartAddress, void * Argument) Line 1153	C
  ntdll.dll!_RtlUserThreadStart(long(__stdcall*)(void *) StartAddress, void * Argument) Line 1070	C
```

# Notes

- This behavior starts showing with Boost 1.70. \
Earlier versions don't run into this bug.
- The bug happens only in the `Release|x86` flavor, when using the `NDEBUG` preprocessor defintion.\
  See `Vc141Boost171.vcxproj`.
- The bug does not happen when building with MSVC 14.2 (`v142`).