
![**Scenario:**](./postmoterm_technical.webp)



A web-based application that provides real-time analytics for marketing campaigns experienced a significant outage. Users were unable to access the dashboard, and data processing was delayed.


### **Postmortem:**

**Issue Summary:**
The outage lasted from 1:00 PM to 2:45 PM UTC on August 22, 2024. During this time, 45% of users were unable to access the analytics dashboard, while the rest experienced slow data loading times. The root cause was a misconfigured API gateway that resulted in failed requests to the backend servers.

**Timeline:**
- **1:00 PM:** The issue was detected when a spike in failed API requests was noticed by the monitoring system.
- **1:05 PM:** The on-call engineer received an alert and began investigating the problem.
- **1:15 PM:** The initial investigation suggested a potential overload on backend servers due to high traffic.
- **1:25 PM:** Attempts to scale up server instances were made, but the issue persisted.
- **1:45 PM:** It was discovered that the API gateway was misconfigured, causing the backend servers to reject incoming requests.
- **2:00 PM:** The incident was escalated to the DevOps team.
- **2:15 PM:** The API gateway configuration was corrected.
- **2:30 PM:** Backend servers were rebooted to clear any lingering issues.
- **2:45 PM:** The service was fully restored, and normal operations resumed.


![**Root Cause and Resolution:**](./postmoterm_root_cause.webp)
The root cause was an incorrect configuration in the API gateway, which caused it to route traffic improperly, leading to request failures. The resolution involved identifying the misconfiguration, correcting the API gateway settings, and rebooting the backend servers to ensure stability.
**Corrective and Preventative Measures:**
To prevent this issue in the future, the following measures should be implemented:
1. **Improve API Gateway Configuration Management:** Ensure that configurations are reviewed and tested thoroughly before deployment.
2. **Add Redundant Monitoring:** Implement additional monitoring to detect misconfigurations in API gateways.
3. **Create a Backup Configuration:** Maintain a backup of previous stable configurations to allow for quick rollbacks.
4. **Automation for Scaling:** Automate the scaling process to prevent delays during traffic spikes.
