#include <boost/asio/connect.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <boost/beast/core.hpp>
#include <boost/beast/http.hpp>
#include <boost/beast/version.hpp>

using namespace boost::beast;

using boost::asio::ip::tcp;
using std::make_unique;
using std::shared_ptr;
using std::string;

int main()
{
	string url = "http://www.columbia.edu/~fdc/picture-of-something.jpg";
	string scheme = "http";
	string host = "columbia.edu";
	string port = "80";
	string target = "/~fdc/picture-of-something.jpg";

	boost::asio::io_context context;
	boost::asio::ip::tcp::resolver resolver{ context };
	auto const resolveResult = resolver.resolve(host, port);
	tcp::socket socket{context};
	connect(socket, resolveResult);

	http::request<http::string_body> request{ http::verb::get, target, 11};
	request.set(http::field::host, host);
	request.set(http::field::user_agent, BOOST_BEAST_VERSION_STRING);

	http::write(socket, request);

	flat_buffer buffer;
	http::response<http::string_body> response;

	http::parser<false, http::string_body> p{ std::move(response) };
	p.body_limit(25 * 1024 * 1024); // 25MB

	http::read(socket, buffer, p.base());
	response = p.release();
	std::stringstream bodyStream;
	bodyStream << response.body();

	error_code ec;
	socket.shutdown(tcp::socket::shutdown_both, ec);
	if (ec && ec != errc::not_connected)
		throw system_error(ec);
}