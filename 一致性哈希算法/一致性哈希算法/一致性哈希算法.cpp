#include<iostream>
#include<string>
#include<set>
#include<list>
#include"md5.h"
using uint = unsigned int;

using namespace std;

class phscialhost;

class virtualhost
{
public:
	virtualhost(string ip, phscialhost* p)
		:ip_(ip)
		,phscialhost_(p)
	{
		md5_ = getMD5(ip_.c_str());
	}

	bool operator<(const virtualhost& host) const
	{
		return md5_ < host.md5_;
	}

	bool operator==(const virtualhost& host) const
	{
		return ip_ == host.ip_;
	}

	const phscialhost* getphscialhost() const
	{
		return phscialhost_;
	}

private:
	string ip_;
	uint md5_;
	phscialhost* phscialhost_;
};

class phscialhost
{
public:
	phscialhost(string ip, int vnumber)
		:ip_(ip)
	{
		for (int i = 0; i < vnumber; i++)
		{
			virtualhosts_.emplace_back(
				ip + "#" + ::to_string(i), this
			);
		}
	}

	string getip() const
	{
		return ip_;
	}

	const list<virtualhost>& getvirtualhosts() const
	{
		return virtualhosts_;
	}
private:
	string ip_;
	list<virtualhost> virtualhosts_; //虚拟结点列表
};

class hash
{
public:
	void addhash(phscialhost& host)
	{
		auto list = host.getvirtualhosts();
		for (auto host : list)
		{
			hash_.insert(host);
		}
	}

	void delhost(phscialhost& host)
	{
		auto list = host.getvirtualhosts();
		for (auto host : list)
		{
			auto it = hash_.find(host);
			if (it != hash_.end())
			{
				hash_.erase(it);
			}
		}
	}

	string gethost(string clientip) const
	{
		uint md5 = getmd5(clientip.c_str());
		for (auto host : hash_)
		{
			if (host.md5 > md5)
			{
				return host.getphscialhost()->getp();
			}
		}
	}
private:
	set<virtualhost> hash_;//一致性哈希环
};