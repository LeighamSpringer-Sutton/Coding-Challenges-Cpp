/*
Leetcode Challenge:
Every email consists of a local name and a domain name, separated by the @ sign.

For example, in alice@leetcode.com, alice is the local name, and leetcode.com is the domain name.

Besides lowercase letters, these emails may contain '.'s or '+'s.

If you add periods ('.') between some characters in the local name part of an email address, mail sent there will be forwarded to the same address without dots in the local name.  For example, "alice.z@leetcode.com" and "alicez@leetcode.com" forward to the same email address.  (Note that this rule does not apply for domain names.)

If you add a plus ('+') in the local name, everything after the first plus sign will be ignored. This allows certain emails to be filtered, for example m.y+name@email.com will be forwarded to my@email.com.  (Again, this rule does not apply for domain names.)

It is possible to use both of these rules at the same time.

Given a list of emails, we send one email to each address in the list.  How many different addresses actually receive mails? 
*/

int numUniqueEmails(vector<string>& emails) {
        int atsign = 0,plussign = 0,counter =0,duplicate =0;
        int len = emails.size();
        string prevstring = "";
        for (int i = 0; i <len; i++){
            for (int j =0; j < emails[i].size(); j++){
                
                atsign = emails[i].find("@");
                plussign = emails[i].find("+");
                
                if (emails[i][j]=='.' && j < atsign){
                    emails[i].replace(j,1,"");
                    
                }
                
            }
            emails[i].replace(plussign,atsign-plussign,"");
            
        }
        for (int i = 0; i < len; i ++){
            duplicate = 0;
            for (int j = i+1; j < len; j++){
                if (emails[i] == emails[j]){
                    duplicate =1;
                }
                    
                }
                if (!duplicate){
                    
                    counter++;
            }
        }
        return counter;
    }

