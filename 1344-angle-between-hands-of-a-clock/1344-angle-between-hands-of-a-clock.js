/**
 * @param {number} hour
 * @param {number} minutes
 * @return {number}
 */
var angleClock = function(hour, minutes) {
    if(hour == 12)
        hour = 0;
    let hourly = (30.0*hour) + (0.5*minutes);
    let minn = 6.0*minutes;
    let diff = Math.abs(hourly - minn);
    return Math.min(diff, 360.0 - diff);
};